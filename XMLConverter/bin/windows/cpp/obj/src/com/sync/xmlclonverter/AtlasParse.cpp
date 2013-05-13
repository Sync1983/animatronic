#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_com_sync_xmlclonverter_AtlasParse
#include <com/sync/xmlclonverter/AtlasParse.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_native_utils_ByteArray
#include <native/utils/ByteArray.h>
#endif
#ifndef INCLUDED_native_utils_CompressionAlgorithm
#include <native/utils/CompressionAlgorithm.h>
#endif
#ifndef INCLUDED_native_utils_IDataInput
#include <native/utils/IDataInput.h>
#endif
#ifndef INCLUDED_native_utils_IMemoryRange
#include <native/utils/IMemoryRange.h>
#endif
namespace com{
namespace sync{
namespace xmlclonverter{

Void AtlasParse_obj::__construct(::Xml xml)
{
HX_STACK_PUSH("AtlasParse::new","com/sync/xmlclonverter/AtlasParse.hx",14);
{
	HX_STACK_LINE(15)
	this->_xml = xml->firstChild();
	HX_STACK_LINE(16)
	this->_name = this->_xml->get(HX_CSTRING("name"));
}
;
	return null();
}

AtlasParse_obj::~AtlasParse_obj() { }

Dynamic AtlasParse_obj::__CreateEmpty() { return  new AtlasParse_obj; }
hx::ObjectPtr< AtlasParse_obj > AtlasParse_obj::__new(::Xml xml)
{  hx::ObjectPtr< AtlasParse_obj > result = new AtlasParse_obj();
	result->__construct(xml);
	return result;}

Dynamic AtlasParse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AtlasParse_obj > result = new AtlasParse_obj();
	result->__construct(inArgs[0]);
	return result;}

::native::utils::ByteArray AtlasParse_obj::parse( ){
	HX_STACK_PUSH("AtlasParse::parse","com/sync/xmlclonverter/AtlasParse.hx",19);
	HX_STACK_THIS(this);
	HX_STACK_LINE(20)
	::native::utils::ByteArray atlas = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(atlas,"atlas");
	HX_STACK_LINE(21)
	::native::utils::ByteArray alias = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(alias,"alias");
	HX_STACK_LINE(22)
	int item = (int)0;		HX_STACK_VAR(item,"item");
	HX_STACK_LINE(23)
	for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(this->_xml->elements());  __it->hasNext(); ){
		::Xml sub = __it->next();
		{
			HX_STACK_LINE(24)
			alias->writeUTF(sub->get(HX_CSTRING("name")));
			HX_STACK_LINE(25)
			alias->writeInt(item);
			HX_STACK_LINE(26)
			atlas->writeInt(item);
			HX_STACK_LINE(27)
			atlas->writeInt(::Std_obj::parseInt(sub->get(HX_CSTRING("x"))));
			HX_STACK_LINE(28)
			atlas->writeInt(::Std_obj::parseInt(sub->get(HX_CSTRING("y"))));
			HX_STACK_LINE(29)
			atlas->writeInt(::Std_obj::parseInt(sub->get(HX_CSTRING("width"))));
			HX_STACK_LINE(30)
			atlas->writeInt(::Std_obj::parseInt(sub->get(HX_CSTRING("height"))));
			HX_STACK_LINE(31)
			(item)++;
		}
;
	}
	HX_STACK_LINE(33)
	alias->compress(null());
	HX_STACK_LINE(34)
	atlas->compress(null());
	HX_STACK_LINE(35)
	::native::utils::ByteArray res = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(37)
	res->writeInt(alias->length);
	HX_STACK_LINE(39)
	res->writeBytes(alias,(int)0,alias->length);
	HX_STACK_LINE(41)
	res->writeInt(atlas->length);
	HX_STACK_LINE(43)
	res->writeBytes(atlas,(int)0,atlas->length);
	HX_STACK_LINE(44)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(AtlasParse_obj,parse,return )


AtlasParse_obj::AtlasParse_obj()
{
}

void AtlasParse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AtlasParse);
	HX_MARK_MEMBER_NAME(_name,"_name");
	HX_MARK_MEMBER_NAME(_xml,"_xml");
	HX_MARK_END_CLASS();
}

void AtlasParse_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_name,"_name");
	HX_VISIT_MEMBER_NAME(_xml,"_xml");
}

Dynamic AtlasParse_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_xml") ) { return _xml; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		if (HX_FIELD_EQ(inName,"_name") ) { return _name; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AtlasParse_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_xml") ) { _xml=inValue.Cast< ::Xml >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_name") ) { _name=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AtlasParse_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_name"));
	outFields->push(HX_CSTRING("_xml"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("parse"),
	HX_CSTRING("_name"),
	HX_CSTRING("_xml"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AtlasParse_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AtlasParse_obj::__mClass,"__mClass");
};

Class AtlasParse_obj::__mClass;

void AtlasParse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.xmlclonverter.AtlasParse"), hx::TCanCast< AtlasParse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AtlasParse_obj::__boot()
{
}

} // end namespace com
} // end namespace sync
} // end namespace xmlclonverter
