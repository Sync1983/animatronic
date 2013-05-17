#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_BonesAtlas
#include <com/sync/bones2/parser/BonesAtlas.h>
#endif
#ifndef INCLUDED_com_sync_bones2_visual_Bone
#include <com/sync/bones2/visual/Bone.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_PixelSnapping
#include <native/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
namespace com{
namespace sync{
namespace bones2{
namespace visual{

Void Bone_obj::__construct(int index,::native::display::BitmapData texture,::haxe::ds::IntMap coords)
{
HX_STACK_PUSH("Bone::new","com/sync/bones2/visual/Bone.hx",32);
{
	HX_STACK_LINE(33)
	if (((coords == null()))){
		HX_STACK_LINE(34)
		return null();
	}
	HX_STACK_LINE(35)
	::native::geom::Rectangle rect = ::native::geom::Rectangle_obj::__new(coords->get(::com::sync::bones2::parser::BonesAtlas_obj::X),coords->get(::com::sync::bones2::parser::BonesAtlas_obj::Y),coords->get(::com::sync::bones2::parser::BonesAtlas_obj::W),coords->get(::com::sync::bones2::parser::BonesAtlas_obj::H));		HX_STACK_VAR(rect,"rect");
	HX_STACK_LINE(36)
	::native::geom::Point point = ::native::geom::Point_obj::__new(null(),null());		HX_STACK_VAR(point,"point");
	HX_STACK_LINE(37)
	this->_bitmap = ::native::display::BitmapData_obj::__new(::Std_obj::_int(rect->width),::Std_obj::_int(rect->height),null(),null(),null());
	HX_STACK_LINE(38)
	this->_bitmap->copyPixels(texture,rect,point,null(),null(),null());
	HX_STACK_LINE(39)
	this->_bmp = ::native::display::Bitmap_obj::__new(this->_bitmap,null(),null());
	HX_STACK_LINE(40)
	point = null();
	HX_STACK_LINE(41)
	rect = null();
}
;
	return null();
}

Bone_obj::~Bone_obj() { }

Dynamic Bone_obj::__CreateEmpty() { return  new Bone_obj; }
hx::ObjectPtr< Bone_obj > Bone_obj::__new(int index,::native::display::BitmapData texture,::haxe::ds::IntMap coords)
{  hx::ObjectPtr< Bone_obj > result = new Bone_obj();
	result->__construct(index,texture,coords);
	return result;}

Dynamic Bone_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bone_obj > result = new Bone_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Bone_obj::addToStage( int x,int y,::native::display::Stage stage){
{
		HX_STACK_PUSH("Bone::addToStage","com/sync/bones2/visual/Bone.hx",54);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(stage,"stage");
		HX_STACK_LINE(54)
		stage->addChild(this->_bmp);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Bone_obj,addToStage,(void))

Void Bone_obj::setupMatrix( Array< Float > boneData){
{
		HX_STACK_PUSH("Bone::setupMatrix","com/sync/bones2/visual/Bone.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_ARG(boneData,"boneData");
		HX_STACK_LINE(45)
		this->_bmp->set_x((boneData->__get(::com::sync::bones2::visual::Bone_obj::X) - boneData->__get(::com::sync::bones2::visual::Bone_obj::pivotX)));
		HX_STACK_LINE(46)
		this->_bmp->set_y((boneData->__get(::com::sync::bones2::visual::Bone_obj::Y) - boneData->__get(::com::sync::bones2::visual::Bone_obj::pivotY)));
		HX_STACK_LINE(47)
		this->_bmp->set_rotation(boneData->__get(::com::sync::bones2::visual::Bone_obj::skewY));
		HX_STACK_LINE(48)
		this->_bmp->set_scaleX(boneData->__get(::com::sync::bones2::visual::Bone_obj::scaleX));
		HX_STACK_LINE(49)
		this->_bmp->set_scaleY(boneData->__get(::com::sync::bones2::visual::Bone_obj::scaleY));
		HX_STACK_LINE(50)
		{
			HX_STACK_LINE(50)
			::native::display::Bitmap _g = this->_bmp;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(50)
			_g->set_x((_g->get_x() + (int)200));
		}
		HX_STACK_LINE(51)
		{
			HX_STACK_LINE(51)
			::native::display::Bitmap _g = this->_bmp;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(51)
			_g->set_y((_g->get_y() + (int)220));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Bone_obj,setupMatrix,(void))

int Bone_obj::X;

int Bone_obj::Y;

int Bone_obj::skewX;

int Bone_obj::skewY;

int Bone_obj::scaleX;

int Bone_obj::scaleY;

int Bone_obj::pivotX;

int Bone_obj::pivotY;

int Bone_obj::z;


Bone_obj::Bone_obj()
{
}

void Bone_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bone);
	HX_MARK_MEMBER_NAME(_bmp,"_bmp");
	HX_MARK_MEMBER_NAME(_bitmap,"_bitmap");
	HX_MARK_MEMBER_NAME(_id,"_id");
	HX_MARK_END_CLASS();
}

void Bone_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_bmp,"_bmp");
	HX_VISIT_MEMBER_NAME(_bitmap,"_bitmap");
	HX_VISIT_MEMBER_NAME(_id,"_id");
}

Dynamic Bone_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"X") ) { return X; }
		if (HX_FIELD_EQ(inName,"Y") ) { return Y; }
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_bmp") ) { return _bmp; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"skewX") ) { return skewX; }
		if (HX_FIELD_EQ(inName,"skewY") ) { return skewY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scaleX") ) { return scaleX; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return scaleY; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { return pivotX; }
		if (HX_FIELD_EQ(inName,"pivotY") ) { return pivotY; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_bitmap") ) { return _bitmap; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addToStage") ) { return addToStage_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setupMatrix") ) { return setupMatrix_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bone_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"X") ) { X=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Y") ) { Y=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_bmp") ) { _bmp=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"skewX") ) { skewX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skewY") ) { skewY=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scaleX") ) { scaleX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { scaleY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { pivotX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pivotY") ) { pivotY=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_bitmap") ) { _bitmap=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bone_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_bmp"));
	outFields->push(HX_CSTRING("_bitmap"));
	outFields->push(HX_CSTRING("_id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("X"),
	HX_CSTRING("Y"),
	HX_CSTRING("skewX"),
	HX_CSTRING("skewY"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("pivotX"),
	HX_CSTRING("pivotY"),
	HX_CSTRING("z"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("addToStage"),
	HX_CSTRING("setupMatrix"),
	HX_CSTRING("_bmp"),
	HX_CSTRING("_bitmap"),
	HX_CSTRING("_id"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bone_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Bone_obj::X,"X");
	HX_MARK_MEMBER_NAME(Bone_obj::Y,"Y");
	HX_MARK_MEMBER_NAME(Bone_obj::skewX,"skewX");
	HX_MARK_MEMBER_NAME(Bone_obj::skewY,"skewY");
	HX_MARK_MEMBER_NAME(Bone_obj::scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(Bone_obj::scaleY,"scaleY");
	HX_MARK_MEMBER_NAME(Bone_obj::pivotX,"pivotX");
	HX_MARK_MEMBER_NAME(Bone_obj::pivotY,"pivotY");
	HX_MARK_MEMBER_NAME(Bone_obj::z,"z");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bone_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Bone_obj::X,"X");
	HX_VISIT_MEMBER_NAME(Bone_obj::Y,"Y");
	HX_VISIT_MEMBER_NAME(Bone_obj::skewX,"skewX");
	HX_VISIT_MEMBER_NAME(Bone_obj::skewY,"skewY");
	HX_VISIT_MEMBER_NAME(Bone_obj::scaleX,"scaleX");
	HX_VISIT_MEMBER_NAME(Bone_obj::scaleY,"scaleY");
	HX_VISIT_MEMBER_NAME(Bone_obj::pivotX,"pivotX");
	HX_VISIT_MEMBER_NAME(Bone_obj::pivotY,"pivotY");
	HX_VISIT_MEMBER_NAME(Bone_obj::z,"z");
};

Class Bone_obj::__mClass;

void Bone_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.bones2.visual.Bone"), hx::TCanCast< Bone_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bone_obj::__boot()
{
	X= (int)0;
	Y= (int)1;
	skewX= (int)2;
	skewY= (int)3;
	scaleX= (int)4;
	scaleY= (int)5;
	pivotX= (int)6;
	pivotY= (int)7;
	z= (int)8;
}

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace visual
