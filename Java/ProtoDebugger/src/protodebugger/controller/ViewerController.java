package protodebugger.controller;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;

import protodebugger.model.ProtoPackageModel;
import protodebugger.model.protos.ProtoPkgContainer.ProtoInstance;
import protodebugger.model.protos.ProtoPkgContainer.ProtoMessage;
import protodebugger.model.protos.ProtoPkgContainer.ProtoPackage;
import protodebugger.util.ProtoEvents;
import protodebugger.views.ProtoCacheViewer;

import com.google.protobuf.ByteString;
import com.google.protobuf.GeneratedMessage;

/**
 * 
 * ViewerController
 * DESCRIPTION: {@link ProtoCacheViewer} controller.
 * Keeps {@link ProtoCacheViewer} in sync with {@link ProtoPackageModel}
 * 
 * PACKAGE: protodebugger.controller
 * @author sloppyjoe -Initial release
 *
 */
public enum ViewerController {

	INSTANCE;
	private ProtoPackageModel packageModel  = new ProtoPackageModel();
	private PropertyChangeSupport pcs = new PropertyChangeSupport(this);
	private ViewerController()
	{
	}
	
	/**
	 * Returns the current model in control
	 * 
	 * @return {@link ProtoPackageModel}
	 */
	public final ProtoPackageModel getModel()
	{
		return packageModel;
	}
	
	public void addProtoPkg(ProtoPackage pkg)
	{
		packageModel.addProtoPkg(pkg);
		pcs.firePropertyChange(ProtoEvents.CACHED_LOADED.name(), null, packageModel );		
	}
	
	public void newProtoInstance(ProtoMessage msg, String name)
	{
		ProtoPackage pkg = packageModel.getPackageForMessage(msg);
		updatePackageModel(pkg, msg.getClassName(), name, 
				ByteString.copyFrom("NEW PROTO".getBytes()),msg.getName());
	}
	
	public void newProtoInstance(ProtoPackage pkg, GeneratedMessage msg, String name)
	{
		updatePackageModel(pkg, msg.getClass().getName(), name, 
				ByteString.copyFrom("NEW PROTO".getBytes()),msg.getDescriptorForType().getName());
	}
	
	public void updatePackageModel(ProtoInstance ins, GeneratedMessage msg)
	{
		ProtoMessage protoMsgParent = packageModel.getMessageForInstance(packageModel.getInstanceFromString(ins.getName()));
		System.out.println("updating the proto instance");
		
		updatePackageModel(packageModel.getPackageForMessage(protoMsgParent), msg.getClass().getName(),
				ins.getName(), ins.getMessage(), msg.getDescriptorForType().getName());
	}
	
	public void updatePackageModel(ProtoPackage pkg, String className, String name, ByteString byteMsg,String protoMsgName)
	{
		try
		{
			this.getModel().removeProtoPk(pkg);
			ProtoInstance.Builder builder = ProtoInstance.newBuilder();
			builder.setName(name);
			builder.setMessage(byteMsg);
			ProtoPackage.Builder protoPkgBuilder = ProtoPackage.newBuilder(pkg);
			boolean foundMessage = false;
			for (int i = 0; i < pkg.getMsgsCount(); ++i)
			{
				if (pkg.getMsgs(i).getClassName().equals(className) )
				{
					ProtoMessage.Builder protoMsgBuilder = ProtoMessage.newBuilder(pkg.getMsgs(i));
					for(int j = 0; j < protoMsgBuilder.getMessageCount() ; j++){
						if(protoMsgBuilder.getMessage(j).getName().equals(name))
						{
							protoMsgBuilder.removeMessage(j);
							break;
						}
					}
					protoMsgBuilder.addMessage(builder.build());
					protoPkgBuilder.removeMsgs(i);
					protoPkgBuilder.addMsgs( protoMsgBuilder.build());
					foundMessage = true;
					break;
				}
			}
			if(!foundMessage){
				protoPkgBuilder.addMsgs(ProtoMessage.newBuilder().addMessage(builder.build()).
						setName(protoMsgName).setClassName(className).build());
			}
			this.getModel().addProtoPkg(protoPkgBuilder.build());
			pcs.firePropertyChange(ProtoEvents.CACHED_LOADED.name(), null, this.getModel() );	
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.out.println(e.getMessage());
		}
	}
	
	public void addChangeListener(PropertyChangeListener pcl)
	{
		pcs.addPropertyChangeListener(pcl);
	}
	
}
