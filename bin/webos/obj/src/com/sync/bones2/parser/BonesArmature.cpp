#include <hxcpp.h>

#ifndef INCLUDED_com_sync_bones2_parser_BonesArmature
#include <com/sync/bones2/parser/BonesArmature.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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

Void BonesArmature_obj::__construct(::native::utils::ByteArray byteArray)
{
HX_STACK_PUSH("BonesArmature::new","com/sync/bones2/parser/BonesArmature.hx",17);
{
	HX_STACK_LINE(18)
	this->_ba = byteArray;
	HX_STACK_LINE(19)
	this->_startPosition = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(20)
	this->parse();
}
;
	return null();
}

BonesArmature_obj::~BonesArmature_obj() { }

Dynamic BonesArmature_obj::__CreateEmpty() { return  new BonesArmature_obj; }
hx::ObjectPtr< BonesArmature_obj > BonesArmature_obj::__new(::native::utils::ByteArray byteArray)
{  hx::ObjectPtr< BonesArmature_obj > result = new BonesArmature_obj();
	result->__construct(byteArray);
	return result;}

Dynamic BonesArmature_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BonesArmature_obj > result = new BonesArmature_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BonesArmature_obj::parse( ){
{
		HX_STACK_PUSH("BonesArmature::parse","com/sync/bones2/parser/BonesArmature.hx",29);
		HX_STACK_THIS(this);
		HX_STACK_LINE(30)
		this->_ba->position = (int)0;
		HX_STACK_LINE(31)
		this->_frameRate = this->_ba->readInt();
		HX_STACK_LINE(32)
		this->_name = this->_ba->readUTF();
		HX_STACK_LINE(34)
		int armatureLength = this->_ba->readInt();		HX_STACK_VAR(armatureLength,"armatureLength");
		HX_STACK_LINE(35)
		::String armatureName = this->_ba->readUTF();		HX_STACK_VAR(armatureName,"armatureName");
		HX_STACK_LINE(36)
		::haxe::Log_obj::trace((((HX_CSTRING("Name: ") + this->_name) + HX_CSTRING(" FrameRate: ")) + this->_frameRate),hx::SourceInfo(HX_CSTRING("BonesArmature.hx"),36,HX_CSTRING("com.sync.bones2.parser.BonesArmature"),HX_CSTRING("parse")));
		HX_STACK_LINE(37)
		while(((this->_ba->position < this->_ba->length))){
			HX_STACK_LINE(39)
			Float X = (Float(this->_ba->readInt()) / Float((int)1000));		HX_STACK_VAR(X,"X");
			HX_STACK_LINE(40)
			Float Y = (Float(this->_ba->readInt()) / Float((int)1000));		HX_STACK_VAR(Y,"Y");
			HX_STACK_LINE(41)
			Float skewX = (Float(this->_ba->readInt()) / Float((int)1000));		HX_STACK_VAR(skewX,"skewX");
			HX_STACK_LINE(42)
			Float skewY = (Float(this->_ba->readInt()) / Float((int)1000));		HX_STACK_VAR(skewY,"skewY");
			HX_STACK_LINE(43)
			Float scaleX = (Float(this->_ba->readInt()) / Float((int)1000));		HX_STACK_VAR(scaleX,"scaleX");
			HX_STACK_LINE(44)
			Float scaleY = (Float(this->_ba->readInt()) / Float((int)1000));		HX_STACK_VAR(scaleY,"scaleY");
			HX_STACK_LINE(45)
			Float pivotX = (Float(this->_ba->readInt()) / Float((int)1000));		HX_STACK_VAR(pivotX,"pivotX");
			HX_STACK_LINE(46)
			Float pivotY = (Float(this->_ba->readInt()) / Float((int)1000));		HX_STACK_VAR(pivotY,"pivotY");
			HX_STACK_LINE(47)
			Float z = this->_ba->readInt();		HX_STACK_VAR(z,"z");
			HX_STACK_LINE(48)
			int atlas = this->_ba->readInt();		HX_STACK_VAR(atlas,"atlas");
			HX_STACK_LINE(49)
			this->_startPosition[atlas] = Array_obj< Float >::__new().Add(X).Add(Y).Add(skewX).Add(skewY).Add(scaleX).Add(scaleY).Add(pivotX).Add(pivotY).Add(z);
		}
		HX_STACK_LINE(59)
		::haxe::Log_obj::trace((HX_CSTRING("Armature: ") + armatureName),hx::SourceInfo(HX_CSTRING("BonesArmature.hx"),59,HX_CSTRING("com.sync.bones2.parser.BonesArmature"),HX_CSTRING("parse")));
		HX_STACK_LINE(60)
		::haxe::Log_obj::trace(this->_startPosition,hx::SourceInfo(HX_CSTRING("BonesArmature.hx"),60,HX_CSTRING("com.sync.bones2.parser.BonesArmature"),HX_CSTRING("parse")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BonesArmature_obj,parse,(void))

Array< Float > BonesArmature_obj::getBoneParams( int atlasId){
	HX_STACK_PUSH("BonesArmature::getBoneParams","com/sync/bones2/parser/BonesArmature.hx",23);
	HX_STACK_THIS(this);
	HX_STACK_ARG(atlasId,"atlasId");
	HX_STACK_LINE(24)
	if (((bool((atlasId < (int)0)) || bool((atlasId >= this->_startPosition->length))))){
		HX_STACK_LINE(25)
		return null();
	}
	HX_STACK_LINE(26)
	return this->_startPosition->__get(atlasId).StaticCast< Array< Float > >();
}


HX_DEFINE_DYNAMIC_FUNC1(BonesArmature_obj,getBoneParams,return )


BonesArmature_obj::BonesArmature_obj()
{
}

void BonesArmature_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BonesArmature);
	HX_MARK_MEMBER_NAME(_startPosition,"_startPosition");
	HX_MARK_MEMBER_NAME(_frameRate,"_frameRate");
	HX_MARK_MEMBER_NAME(_name,"_name");
	HX_MARK_MEMBER_NAME(_ba,"_ba");
	HX_MARK_END_CLASS();
}

void BonesArmature_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_startPosition,"_startPosition");
	HX_VISIT_MEMBER_NAME(_frameRate,"_frameRate");
	HX_VISIT_MEMBER_NAME(_name,"_name");
	HX_VISIT_MEMBER_NAME(_ba,"_ba");
}

Dynamic BonesArmature_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_ba") ) { return _ba; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		if (HX_FIELD_EQ(inName,"_name") ) { return _name; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_frameRate") ) { return _frameRate; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getBoneParams") ) { return getBoneParams_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_startPosition") ) { return _startPosition; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BonesArmature_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_ba") ) { _ba=inValue.Cast< ::native::utils::ByteArray >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_name") ) { _name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_frameRate") ) { _frameRate=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_startPosition") ) { _startPosition=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BonesArmature_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_startPosition"));
	outFields->push(HX_CSTRING("_frameRate"));
	outFields->push(HX_CSTRING("_name"));
	outFields->push(HX_CSTRING("_ba"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("parse"),
	HX_CSTRING("getBoneParams"),
	HX_CSTRING("_startPosition"),
	HX_CSTRING("_frameRate"),
	HX_CSTRING("_name"),
	HX_CSTRING("_ba"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BonesArmature_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BonesArmature_obj::__mClass,"__mClass");
};

Class BonesArmature_obj::__mClass;

void BonesArmature_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.bones2.parser.BonesArmature"), hx::TCanCast< BonesArmature_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BonesArmature_obj::__boot()
{
}

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace parser
