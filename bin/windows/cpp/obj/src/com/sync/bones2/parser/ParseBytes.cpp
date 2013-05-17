#include <hxcpp.h>

#ifndef INCLUDED_com_sync_bones2_parser_BonesAlias
#include <com/sync/bones2/parser/BonesAlias.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_BonesArmature
#include <com/sync/bones2/parser/BonesArmature.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_BonesAtlas
#include <com/sync/bones2/parser/BonesAtlas.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_ParseBytes
#include <com/sync/bones2/parser/ParseBytes.h>
#endif
#ifndef INCLUDED_com_sync_bones2_visual_BonesManager
#include <com/sync/bones2/visual/BonesManager.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
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

Void ParseBytes_obj::__construct(::native::utils::ByteArray byteArray,::native::display::BitmapData texture)
{
HX_STACK_PUSH("ParseBytes::new","com/sync/bones2/parser/ParseBytes.hx",20);
{
	HX_STACK_LINE(21)
	this->_ba = byteArray;
	HX_STACK_LINE(22)
	this->_bitmap = texture;
	HX_STACK_LINE(23)
	this->_parse();
}
;
	return null();
}

ParseBytes_obj::~ParseBytes_obj() { }

Dynamic ParseBytes_obj::__CreateEmpty() { return  new ParseBytes_obj; }
hx::ObjectPtr< ParseBytes_obj > ParseBytes_obj::__new(::native::utils::ByteArray byteArray,::native::display::BitmapData texture)
{  hx::ObjectPtr< ParseBytes_obj > result = new ParseBytes_obj();
	result->__construct(byteArray,texture);
	return result;}

Dynamic ParseBytes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParseBytes_obj > result = new ParseBytes_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void ParseBytes_obj::_parse( ){
{
		HX_STACK_PUSH("ParseBytes::_parse","com/sync/bones2/parser/ParseBytes.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_LINE(27)
		this->_ba->position = (int)0;
		HX_STACK_LINE(28)
		::native::utils::ByteArray alias = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(alias,"alias");
		HX_STACK_LINE(29)
		::native::utils::ByteArray atlas = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(atlas,"atlas");
		HX_STACK_LINE(30)
		::native::utils::ByteArray armatures = ::native::utils::ByteArray_obj::__new(null());		HX_STACK_VAR(armatures,"armatures");
		HX_STACK_LINE(31)
		int aliasLength = this->_ba->readInt();		HX_STACK_VAR(aliasLength,"aliasLength");
		HX_STACK_LINE(32)
		alias->writeBytes(this->_ba,(int)4,aliasLength);
		HX_STACK_LINE(33)
		this->_ba->position = (aliasLength + (int)4);
		HX_STACK_LINE(34)
		int atlasLength = this->_ba->readInt();		HX_STACK_VAR(atlasLength,"atlasLength");
		HX_STACK_LINE(35)
		atlas->writeBytes(this->_ba,((int)8 + aliasLength),atlasLength);
		HX_STACK_LINE(36)
		this->_ba->position = (((int)8 + aliasLength) + atlasLength);
		HX_STACK_LINE(37)
		int armaturesLength = this->_ba->readInt();		HX_STACK_VAR(armaturesLength,"armaturesLength");
		HX_STACK_LINE(38)
		armatures->writeBytes(this->_ba,this->_ba->position,armaturesLength);
		HX_STACK_LINE(39)
		this->alias = ::com::sync::bones2::parser::BonesAlias_obj::__new(alias);
		HX_STACK_LINE(40)
		this->atlas = ::com::sync::bones2::parser::BonesAtlas_obj::__new(atlas);
		HX_STACK_LINE(41)
		this->armatures = ::com::sync::bones2::parser::BonesArmature_obj::__new(armatures);
		HX_STACK_LINE(42)
		this->bonesManager = ::com::sync::bones2::visual::BonesManager_obj::__new(this->alias,this->atlas,this->_bitmap,this->armatures);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParseBytes_obj,_parse,(void))


ParseBytes_obj::ParseBytes_obj()
{
}

void ParseBytes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParseBytes);
	HX_MARK_MEMBER_NAME(_bitmap,"_bitmap");
	HX_MARK_MEMBER_NAME(_ba,"_ba");
	HX_MARK_MEMBER_NAME(bonesManager,"bonesManager");
	HX_MARK_MEMBER_NAME(armatures,"armatures");
	HX_MARK_MEMBER_NAME(atlas,"atlas");
	HX_MARK_MEMBER_NAME(alias,"alias");
	HX_MARK_END_CLASS();
}

void ParseBytes_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_bitmap,"_bitmap");
	HX_VISIT_MEMBER_NAME(_ba,"_ba");
	HX_VISIT_MEMBER_NAME(bonesManager,"bonesManager");
	HX_VISIT_MEMBER_NAME(armatures,"armatures");
	HX_VISIT_MEMBER_NAME(atlas,"atlas");
	HX_VISIT_MEMBER_NAME(alias,"alias");
}

Dynamic ParseBytes_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_ba") ) { return _ba; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { return atlas; }
		if (HX_FIELD_EQ(inName,"alias") ) { return alias; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_parse") ) { return _parse_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_bitmap") ) { return _bitmap; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"armatures") ) { return armatures; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"bonesManager") ) { return bonesManager; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ParseBytes_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_ba") ) { _ba=inValue.Cast< ::native::utils::ByteArray >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { atlas=inValue.Cast< ::com::sync::bones2::parser::BonesAtlas >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alias") ) { alias=inValue.Cast< ::com::sync::bones2::parser::BonesAlias >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_bitmap") ) { _bitmap=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"armatures") ) { armatures=inValue.Cast< ::com::sync::bones2::parser::BonesArmature >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"bonesManager") ) { bonesManager=inValue.Cast< ::com::sync::bones2::visual::BonesManager >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ParseBytes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_bitmap"));
	outFields->push(HX_CSTRING("_ba"));
	outFields->push(HX_CSTRING("bonesManager"));
	outFields->push(HX_CSTRING("armatures"));
	outFields->push(HX_CSTRING("atlas"));
	outFields->push(HX_CSTRING("alias"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_parse"),
	HX_CSTRING("_bitmap"),
	HX_CSTRING("_ba"),
	HX_CSTRING("bonesManager"),
	HX_CSTRING("armatures"),
	HX_CSTRING("atlas"),
	HX_CSTRING("alias"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParseBytes_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParseBytes_obj::__mClass,"__mClass");
};

Class ParseBytes_obj::__mClass;

void ParseBytes_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.bones2.parser.ParseBytes"), hx::TCanCast< ParseBytes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ParseBytes_obj::__boot()
{
}

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace parser
