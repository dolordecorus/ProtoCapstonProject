#include <QWidget>

using namespace std;
using namespace google;
using namespace protobuf;

template <class Object> class FieldDescriptorContainer
{
    protected:
        bool m_subfield;
        FieldDescriptorContainer * parent;
        Object m_value;
        Object m_defaultValue;

    public:
        string m_name;
        FieldDescriptor m_field;
        virtual QWidget * getWidget(QWidget *parent = 0) = 0;
        virtual QWidget * getParent() = 0;
        virtual string getValue() = 0;
        virtual void setValue(string object) = 0;
        virtual string toString() = 0;
        //virtual buildMsg() = 0;

        FieldDescriptorContainer(FieldDescriptor field)
        {
            m_field = field;
            m_name = field.name();

            //Set the default value depending on type
            if(field.has_default_value())
            {
                switch(FieldDescriptor::Type)
                {
                    case FieldDescriptor::CPPTYPE_BOOL:
                    {
                        m_defaultValue = field.default_value_bool();
                        break;
                    }
                    case FieldDescriptor::CPPTYPE_DOUBLE:
                    {
                        m_defaultValue = field.default_value_double();
                        break;
                    }
                    case FieldDescriptor::CPPTYPE_ENUM:
                    {
                         m_defaultValue = field.default_value_enum();
                        break;
                    }
                    case FieldDescriptor::CPPTYPE_FLOAT:
                    {
                        m_defaultValue = field.default_value_float();
                        break;
                    }
                    case FieldDescriptor::CPPTYPE_INT32:
                    {
                        m_defaultValue = field.default_value_int32();
                        break;
                    }
                    case FieldDescriptor::CPPTYPE_INT64:
                    {
                        m_defaultValue = field.default_value_int64();
                        break;
                    }
                    case FieldDescriptor::CPPTYPE_MESSAGE:
                    {
                        m_defaultValue = NULL;
                        break;
                    }
                    case FieldDescriptor::CPPTYPE_STRING:
                    {
                        field.default_value_string();
                        break;
                    }
                    case FieldDescriptor::CPPTYPE_UINT32:
                    {
                        field.default_value_uint32();
                        break;
                    }
                    default:
                    {
                        m_defaultValue = field.default_value_uint64();
                        break;
                    }
                }
            }
        }

        bool isSubField()
        {
            return m_subfield;
        }

        void setSubfield(bool sub)
        {
            m_subfield = sub;
        }

        void setFieldParent(FieldDescriptorContainer * parent)
        {
            this->parent = parent;
        }

        FieldDescriptorContainer * getFieldParent()
        {
            if(m_subfield)
            {
             return parent;
            }
            return NULL;
        }
};

#endif // FIELDDESCRIPTORCONTAINER_H
