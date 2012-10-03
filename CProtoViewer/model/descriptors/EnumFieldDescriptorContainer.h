#ifndef ENUMFIELDDESCRIPTORCONTAINER_H
#define ENUMFIELDDESCRIPTORCONTAINER_H

#include "FieldDescriptorContainer.h"

//protobuf
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>

//Qt
#include <QComboBox>
#include <QWidget>
#include <QStringList>

class EnumFieldDescriptorContainer : public FieldDescriptorContainer
{
    protected:

    private:
        QComboBox * m_comboField;
        const google::protobuf::EnumValueDescriptor * m_defaultValue;
        const google::protobuf::EnumValueDescriptor * m_value;

        //Helper function
        bool equals(std::string param1, std::string param2)
        {
            bool result = true;
            if(param1.empty() && param2.empty())
            {
                return result;
            }
            if( param1.length() == param2.length())
            {
                for(uint i = 0; i < param1.length(); ++i)
                {
                    if(param1.at(i) != param2.at(i))
                    {
                        result = false;
                    }
                }
            }

            return result;
        }

    public:
        std::string m_name;
        google::protobuf::FieldDescriptor * m_field;
        EnumFieldDescriptorContainer(google::protobuf::FieldDescriptor * field);
        ~EnumFieldDescriptorContainer();
        QStringList getValues();
//        google::protobuf::EnumValueDescriptorProto * buildMsg();

        //Inherited functions
        virtual void setValue( std::string object);
        virtual std::string getValue(); //Cast to EnumValueDescriptor
        virtual std::string toString();
        virtual QWidget * getWidget(QWidget *parent = 0);
        virtual QWidget * getParent();
};

#endif // ENUMFIELDDESCRIPTORCONTAINER_H
