#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_com_sync_bones2_Main
#include <com/sync/bones2/Main.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_ParseBytes
#include <com/sync/bones2/parser/ParseBytes.h>
#endif
#ifndef INCLUDED_com_sync_bones2_visual_Bone
#include <com/sync/bones2/visual/Bone.h>
#endif
#ifndef INCLUDED_com_sync_bones2_visual_BonesManager
#include <com/sync/bones2/visual/BonesManager.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
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
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_display_StageAlign
#include <native/display/StageAlign.h>
#endif
#ifndef INCLUDED_native_display_StageScaleMode
#include <native/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
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
#ifndef INCLUDED_nme_Assets
#include <nme/Assets.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace com{
namespace sync{
namespace bones2{

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","com/sync/bones2/Main.hx",49);
{
	HX_STACK_LINE(50)
	super::__construct();
	HX_STACK_LINE(51)
	this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null(),null(),null());
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::added( Dynamic e){
{
		HX_STACK_PUSH("Main::added","com/sync/bones2/Main.hx",55);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(56)
		this->removeEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null());
		HX_STACK_LINE(57)
		this->get_stage()->addEventListener(::native::events::Event_obj::RESIZE,this->resize_dyn(),null(),null(),null());
		HX_STACK_LINE(61)
		this->init();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,added,(void))

Void Main_obj::init( ){
{
		HX_STACK_PUSH("Main::init","com/sync/bones2/Main.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_LINE(32)
		if ((this->inited)){
			HX_STACK_LINE(32)
			return null();
		}
		HX_STACK_LINE(33)
		this->inited = true;
		HX_STACK_LINE(35)
		this->img = ::nme::Assets_obj::getBitmapData(HX_CSTRING("img/Vikasa_output.png"),null());
		HX_STACK_LINE(37)
		this->ba = ::nme::Assets_obj::getBytes(HX_CSTRING("bins/binary.bin"));
		HX_STACK_LINE(39)
		::com::sync::bones2::parser::ParseBytes parser = ::com::sync::bones2::parser::ParseBytes_obj::__new(this->ba,this->img);		HX_STACK_VAR(parser,"parser");
		HX_STACK_LINE(40)
		{
			HX_STACK_LINE(40)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = ::Lambda_obj::count(parser->bonesManager->bones,null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(40)
			while(((_g1 < _g))){
				HX_STACK_LINE(40)
				int index = (_g1)++;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(41)
				parser->bonesManager->bones->get(index)->__Field(HX_CSTRING("addToStage"),true)((int)0,(int)0,this->get_stage());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,init,(void))

Void Main_obj::resize( Dynamic e){
{
		HX_STACK_PUSH("Main::resize","com/sync/bones2/Main.hx",25);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(25)
		if ((!(this->inited))){
			HX_STACK_LINE(26)
			this->init();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,resize,(void))

Void Main_obj::main( ){
{
		HX_STACK_PUSH("Main::main","com/sync/bones2/Main.hx",66);
		HX_STACK_LINE(68)
		::nme::Lib_obj::get_current()->get_stage()->set_align(::native::display::StageAlign_obj::TOP_LEFT);
		HX_STACK_LINE(69)
		::nme::Lib_obj::get_current()->get_stage()->set_scaleMode(::native::display::StageScaleMode_obj::NO_SCALE);
		HX_STACK_LINE(70)
		::nme::Lib_obj::get_current()->addChild(::com::sync::bones2::Main_obj::__new());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(ba,"ba");
	HX_MARK_MEMBER_NAME(img,"img");
	HX_MARK_MEMBER_NAME(inited,"inited");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ba,"ba");
	HX_VISIT_MEMBER_NAME(img,"img");
	HX_VISIT_MEMBER_NAME(inited,"inited");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ba") ) { return ba; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"img") ) { return img; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"added") ) { return added_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		if (HX_FIELD_EQ(inName,"inited") ) { return inited; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ba") ) { ba=inValue.Cast< ::native::utils::ByteArray >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"img") ) { img=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { inited=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ba"));
	outFields->push(HX_CSTRING("img"));
	outFields->push(HX_CSTRING("inited"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("added"),
	HX_CSTRING("init"),
	HX_CSTRING("resize"),
	HX_CSTRING("ba"),
	HX_CSTRING("img"),
	HX_CSTRING("inited"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.bones2.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

} // end namespace com
} // end namespace sync
} // end namespace bones2
