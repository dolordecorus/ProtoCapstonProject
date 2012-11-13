package protodebugger.views.menus;
import java.util.LinkedHashMap;
import java.util.Map;

import org.eclipse.jface.dialogs.IInputValidator;
import org.eclipse.jface.dialogs.InputDialog;
import org.eclipse.jface.window.Window;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.MenuEvent;
import org.eclipse.swt.events.MenuListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;
import org.test.AddressBookProtos.AddressBook;
import org.test.AddressBookProtos.Person;
import org.test.AlienSpeciesProto.Alien;
import org.test.AlienSpeciesProto.AlienSpecies;

import protodebugger.controller.ViewerController;
import protodebugger.model.protos.ProtoPkgContainer.ProtoPackage;

import com.google.protobuf.GeneratedMessage;

public class ProtoCacheViewerMenu extends SelectionAdapter implements MenuListener 
{
	private Menu menu;
	private ProtoPackage pkg;
	private final Map<String, GeneratedMessage> messageList = new LinkedHashMap<String, GeneratedMessage>();
	{
		messageList.put("AddressBook", Person.getDefaultInstance());
		messageList.put("AlienSpecies", Alien.getDefaultInstance());
	}
	private MenuItem selectMenuItem;

	public ProtoCacheViewerMenu(Menu menu) {
		this.menu = menu;
		selectMenuItem = new MenuItem(menu, SWT.CASCADE);
		selectMenuItem.setText("Select Proto");
	}

	public void setModel(ProtoPackage pkg) {
		this.pkg = pkg;
	}
	
	@Override
	public void menuHidden(MenuEvent e) {
	}

	@Override
	public void menuShown(MenuEvent e) 
	{
		resetMenu();
		if (pkg != null) {
			createSelectSubItems();
		}
	}

	private void resetMenu() {
		if(selectMenuItem.getMenu() != null)
			selectMenuItem.getMenu().dispose();
	}

	private void createSelectSubItems() {
		if (!messageList.isEmpty()) {
			Menu selectMenu = new Menu(selectMenuItem);
			selectMenuItem.setMenu(selectMenu);
			for ( String key : messageList.keySet()) 
			{
				System.out.println("Adding " + key);
				MenuItem item = new MenuItem(selectMenu, SWT.NONE);
				item.setText(key);
				item.setData(messageList.get(key));
				item.addSelectionListener(this);
			}
			selectMenuItem.setEnabled(true);
		}
		else
		{
			selectMenuItem.setEnabled(false);
		}
	}

	@Override
	public void widgetSelected(SelectionEvent e) {
		if (e.getSource() instanceof MenuItem) {
			MenuItem item = (MenuItem) e.getSource();
			if (item.getParent().getParentMenu() != null) {
				if (item.getParent().equals(selectMenuItem.getMenu())) {
					Object data = item.getData();
					if (data != null && data instanceof GeneratedMessage) 
					{
						String name;
				        IInputValidator validator = new IInputValidator() {
				            public String isValid(String newText) {
				                return null;
				            }
				          };
				          InputDialog dialog = new InputDialog(Display.getCurrent().getActiveShell(), "Proto Name", "Please name this proto message", "", validator);
				          if(dialog.open() == Window.OK) 
				          {
				            name = dialog.getValue();
							ViewerController.INSTANCE.newProtoInstance(pkg, (GeneratedMessage)data, name);
				          }
					}
				} 
			}
		}
	}

}