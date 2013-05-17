#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_BonesAlias
#include <com/sync/bones2/parser/BonesAlias.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_native_utils_ByteArray
#include <native/utils/ByteArray.h>
#endif
#ifndef INCLUDED_native_utils_IDataInput
#include <native/utils/IDataInput.h>
#endif
#ifndef INCLUDED_native_utils_IMemoryRange
#include <native/utils/IMemoryRange.h>
#endif
namespace com{
namespace sync{
namespace bones2{
namespace parser{

Void BonesAlias_obj::__construct(::native::utils::ByteArray byteArray)
{
HX_STACK_PUSH("BonesAlias::new","com/sync/bones2/parser/BonesAlias.hx",14);
{
	HX_STACK_LINE(15)
	this->_ba = byteArray;
	HX_STACK_LINE(16)
	byteArray = null();
	HX_STACK_LINE(17)
	this->_names = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(18)
	this->_parse();
}
;
	return null();
}

BonesAlias_obj::~BonesAlias_obj() { }

Dynamic BonesAlias_obj::__CreateEmpty() { return  new BonesAlias_obj; }
hx::ObjectPtr< BonesAlias_obj > BonesAlias_obj::__new(::native::utils::ByteArray byteArray)
{  hx::ObjectPtr< BonesAlias_obj > result = new BonesAlias_obj();
	result->__construct(byteArray);
	return result;}

Dynamic BonesAlias_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BonesAlias_obj > result = new BonesAlias_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BonesAlias_obj::_parse( ){
{
		HX_STACK_PUSH("BonesAlias::_parse","com/sync/bones2/parser/BonesAlias.hx",25);
		HX_STACK_THIS(this);
		HX_STACK_LINE(26)
		this->_ba->position = (int)0;
		HX_STACK_LINE(27)
		while(((this->_ba->position < this->_ba->length))){
			HX_STACK_LINE(28)
			::String name = this->_ba->readUTF();		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(29)
			int index = this->_ba->readInt();		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(30)
			{
				HX_STACK_LINE(30)
				this->_names->set(index,name);
				HX_STACK_LINE(30)
				name;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BonesAlias_obj,_parse,(void))

::haxe::ds::IntMap BonesAlias_obj::getNames( ){
	HX_STACK_PUSH("BonesAlias::getNames","com/sync/bones2/parser/BonesAlias.hx",21);
	HX_STACK_THIS(this);
	HX_STACK_LINE(21)
	return this->_names;
}


HX_DEFINE_DYNAMIC_FUNC0(BonesAlias_obj,getNames,return )


BonesAlias_obj::BonesAlias_obj()
{
}

void BonesAlias_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BonesAlias);
	HX_MARK_MEMBER_NAME(_names,"_names");
	HX_MARK_MEMBER_NAME(_ba,"_ba");
	HX_MARK_END_CLASS();
}

void BonesAlias_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_names,"_names");
	HX_VISIT_MEMBER_NAME(_ba,"_ba");
}

Dynamic BonesAlias_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_ba") ) { return _ba; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_parse") ) { return _parse_dyn(); }
		if (HX_FIELD_EQ(inName,"_names") ) { return _names; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getNames") ) { return getNames_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BonesAlias_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_ba") ) { _ba=inValue.Cast< ::native::utils::ByteArray >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_names") ) { _names=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BonesAlias_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_names"));
	outFields->push(HX_CSTRING("_ba"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_parse"),
	HX_CSTRING("getNames"),
	HX_CSTRING("_names"),
	HX_CSTRING("_ba"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BonesAlias_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BonesAlias_obj::__mClass,"__mClass");
};

Class BonesAlias_obj::__mClass;

void BonesAlias_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.bones2.parser.BonesAlias"), hx::TCanCast< BonesAlias_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BonesAlias_obj::__boot()
{
}

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace parser
