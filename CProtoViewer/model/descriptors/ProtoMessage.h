new
...	@@ -0,0 1,86 @@
1	#ifndef PROTOMESSAGE_H
2	 #define PROTOMESSAGE_H
3
4	//protobuf
5	#include <google/protobuf/descriptor.h>
6	#include <google/protobuf/descriptor.pb.h>
7	#include <google/protobuf/message.h>
8
9   //Qt
10	#include <QWidget>
11
12	#include "FieldDescriptorContainer.h"
13
14	using namespace std;
15	using namespace google;
16	using namespace protobuf;
17
18	template <class Object> class ProtoMessage
19	{
20	    private:
21	        Message::Message m_genMsg;
22	        list<FieldDescriptorContainer> m_contents;
23	        list<FieldDescriptorContainer> m_repeatedFields;
24          list<FieldDescriptorContainer> m_addFields;
25
26	    public:
27	        ProtoMessage(Message::Message genMsg, list<FieldDescriptorContainer> contents,
28	                     list<FieldDescriptorContainer> repeatedField, list<FieldDescriptorContainer> addFields)
29	        {
30	            m_genMsg = genMsg;
31	            m_contents = contents;
32	            m_repeatedFields = repeatedFields;
33	        }
34
35	        Message::Message getGenMsg()
36	        {
37	            return m_genMsg;
38	        }
39
40	        void setGenMsg(Message::Message genMsg)
41	        {
42	            m_genMsg = genMsg;
43	        }
44
45	        list<FieldDescriptorContainer> getContents()
46	        {
47	            return m_contents;
48	        }
49	        void setContents(list<FieldDescriptorContainer> contents)
50	        {
51	            m_conents = contents;
52	        }
53
54	        list<FieldDescriptorContainer> getRepeatedFields()
55	        {
56	            return m_repeatedFields;
57	        }
58	        void setRepeatedFields(list<FieldDescriptorContainer> repeatedFields)
59	        {
60	            m_repeatedFields = repeatedFields;
61	        }
62
63	        void addAddField(FieldDescriptorContainer add)
64	        {
65	            if(addFields == NULL)
66	            {
67	                m_addFields = new list<FieldDescriptorContainer>();
68	            }
69	            m_addFields.insert(add);
70	        }
71	        void removeAddField(FieldDescriptorContainer remove)
72	        {
73	            if(addFields == NULL)
74	            {
75	                return;
76	            }
77	            m_addFields.remove(remove);
78	        }
79
80	        list<FieldDescriptorContainer> getAddFields()
81	        {
82	            return m_addFields;
83	        }
84	};
85
86	#endif // PROTOMESSAGE_H
