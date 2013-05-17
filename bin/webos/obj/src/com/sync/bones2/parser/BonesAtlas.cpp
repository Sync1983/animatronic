#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_BonesAtlas
#include <com/sync/bones2/parser/BonesAtlas.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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

Void BonesAtlas_obj::__construct(::native::utils::ByteArray byteArray)
{
HX_STACK_PUSH("BonesAtlas::new","com/sync/bones2/parser/BonesAtlas.hx",19);
{
	HX_STACK_LINE(20)
	this->_ba = byteArray;
	HX_STACK_LINE(21)
	byteArray = null();
	HX_STACK_LINE(22)
	this->_coords = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(23)
	this->_parse();
}
;
	return null();
}

BonesAtlas_obj::~BonesAtlas_obj() { }

Dynamic BonesAtlas_obj::__CreateEmpty() { return  new BonesAtlas_obj; }
hx::ObjectPtr< BonesAtlas_obj > BonesAtlas_obj::__new(::native::utils::ByteArray byteArray)
{  hx::ObjectPtr< BonesAtlas_obj > result = new BonesAtlas_obj();
	result->__construct(byteArray);
	return result;}

Dynamic BonesAtlas_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BonesAtlas_obj > result = new BonesAtlas_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BonesAtlas_obj::_parse( ){
{
		HX_STACK_PUSH("BonesAtlas::_parse","com/sync/bones2/parser/BonesAtlas.hx",32);
		HX_STACK_THIS(this);
		HX_STACK_LINE(33)
		::haxe::Log_obj::trace(this->_ba->length,hx::SourceInfo(HX_CSTRING("BonesAtlas.hx"),33,HX_CSTRING("com.sync.bones2.parser.BonesAtlas"),HX_CSTRING("_parse")));
		HX_STACK_LINE(34)
		this->_ba->position = (int)0;
		HX_STACK_LINE(35)
		while(((this->_ba->position < this->_ba->length))){
			HX_STACK_LINE(36)
			::haxe::ds::IntMap item = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(item,"item");
			HX_STACK_LINE(37)
			int index = this->_ba->readInt();		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(38)
			{
				HX_STACK_LINE(38)
				int v = this->_ba->readInt();		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(38)
				item->set(::com::sync::bones2::parser::BonesAtlas_obj::X,v);
				HX_STACK_LINE(38)
				v;
			}
			HX_STACK_LINE(39)
			{
				HX_STACK_LINE(39)
				int v = this->_ba->readInt();		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(39)
				item->set(::com::sync::bones2::parser::BonesAtlas_obj::Y,v);
				HX_STACK_LINE(39)
				v;
			}
			HX_STACK_LINE(40)
			{
				HX_STACK_LINE(40)
				int v = this->_ba->readInt();		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(40)
				item->set(::com::sync::bones2::parser::BonesAtlas_obj::W,v);
				HX_STACK_LINE(40)
				v;
			}
			HX_STACK_LINE(41)
			{
				HX_STACK_LINE(41)
				int v = this->_ba->readInt();		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(41)
				item->set(::com::sync::bones2::parser::BonesAtlas_obj::H,v);
				HX_STACK_LINE(41)
				v;
			}
			HX_STACK_LINE(42)
			this->_coords->set(index,item);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BonesAtlas_obj,_parse,(void))

::haxe::ds::IntMap BonesAtlas_obj::getBoneAtlas( int boneIndex){
	HX_STACK_PUSH("BonesAtlas::getBoneAtlas","com/sync/bones2/parser/BonesAtlas.hx",26);
	HX_STACK_THIS(this);
	HX_STACK_ARG(boneIndex,"boneIndex");
	HX_STACK_LINE(27)
	if (((::Lambda_obj::count(this->_coords,null()) < boneIndex))){
		HX_STACK_LINE(28)
		return null();
	}
	HX_STACK_LINE(29)
	return this->_coords->get(boneIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(BonesAtlas_obj,getBoneAtlas,return )

int BonesAtlas_obj::X;

int BonesAtlas_obj::Y;

int BonesAtlas_obj::W;

int BonesAtlas_obj::H;


BonesAtlas_obj::BonesAtlas_obj()
{
}

void BonesAtlas_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BonesAtlas);
	HX_MARK_MEMBER_NAME(_coords,"_coords");
	HX_MARK_MEMBER_NAME(_ba,"_ba");
	HX_MARK_END_CLASS();
}

void BonesAtlas_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_coords,"_coords");
	HX_VISIT_MEMBER_NAME(_ba,"_ba");
}

Dynamic BonesAtlas_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"X") ) { return X; }
		if (HX_FIELD_EQ(inName,"Y") ) { return Y; }
		if (HX_FIELD_EQ(inName,"W") ) { return W; }
		if (HX_FIELD_EQ(inName,"H") ) { return H; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"_ba") ) { return _ba; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_parse") ) { return _parse_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_coords") ) { return _coords; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getBoneAtlas") ) { return getBoneAtlas_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BonesAtlas_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"X") ) { X=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Y") ) { Y=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"W") ) { W=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"H") ) { H=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"_ba") ) { _ba=inValue.Cast< ::native::utils::ByteArray >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_coords") ) { _coords=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BonesAtlas_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_coords"));
	outFields->push(HX_CSTRING("_ba"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("X"),
	HX_CSTRING("Y"),
	HX_CSTRING("W"),
	HX_CSTRING("H"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_parse"),
	HX_CSTRING("getBoneAtlas"),
	HX_CSTRING("_coords"),
	HX_CSTRING("_ba"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BonesAtlas_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BonesAtlas_obj::X,"X");
	HX_MARK_MEMBER_NAME(BonesAtlas_obj::Y,"Y");
	HX_MARK_MEMBER_NAME(BonesAtlas_obj::W,"W");
	HX_MARK_MEMBER_NAME(BonesAtlas_obj::H,"H");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BonesAtlas_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BonesAtlas_obj::X,"X");
	HX_VISIT_MEMBER_NAME(BonesAtlas_obj::Y,"Y");
	HX_VISIT_MEMBER_NAME(BonesAtlas_obj::W,"W");
	HX_VISIT_MEMBER_NAME(BonesAtlas_obj::H,"H");
};

Class BonesAtlas_obj::__mClass;

void BonesAtlas_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.bones2.parser.BonesAtlas"), hx::TCanCast< BonesAtlas_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BonesAtlas_obj::__boot()
{
	X= (int)0;
	Y= (int)1;
	W= (int)2;
	H= (int)3;
}

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace parser
