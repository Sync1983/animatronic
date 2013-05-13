#include <hxcpp.h>

#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_com_sync_xmlclonverter_AtlasParse
#include <com/sync/xmlclonverter/AtlasParse.h>
#endif
#ifndef INCLUDED_com_sync_xmlclonverter_Main
#include <com/sync/xmlclonverter/Main.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
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
#ifndef INCLUDED_native_net_URLLoader
#include <native/net/URLLoader.h>
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
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
namespace com{
namespace sync{
namespace xmlclonverter{

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","com/sync/xmlclonverter/Main.hx",63);
{
	HX_STACK_LINE(64)
	super::__construct();
	HX_STACK_LINE(65)
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
		HX_STACK_PUSH("Main::added","com/sync/xmlclonverter/Main.hx",69);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(70)
		this->removeEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null());
		HX_STACK_LINE(71)
		this->init();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,added,(void))

Void Main_obj::onLoaderComplite( ::native::events::Event event){
{
		HX_STACK_PUSH("Main::onLoaderComplite","com/sync/xmlclonverter/Main.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(54)
		::native::net::URLLoader loader = event->get_currentTarget();		HX_STACK_VAR(loader,"loader");
		HX_STACK_LINE(55)
		loader->removeEventListener(::native::events::Event_obj::COMPLETE,this->onLoaderComplite_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onLoaderComplite,(void))

Void Main_obj::init( ){
{
		HX_STACK_PUSH("Main::init","com/sync/xmlclonverter/Main.hx",28);
		HX_STACK_THIS(this);
		HX_STACK_LINE(29)
		if ((this->inited)){
			HX_STACK_LINE(29)
			return null();
		}
		HX_STACK_LINE(30)
		this->inited = true;
		HX_STACK_LINE(33)
		this->atlas = ::Xml_obj::parse(::nme::installer::Assets_obj::getText(HX_CSTRING("assets/Atlas.xml")));
		HX_STACK_LINE(34)
		this->scelet = ::Xml_obj::parse(::nme::installer::Assets_obj::getText(HX_CSTRING("assets/XNLData.xml")));
		HX_STACK_LINE(35)
		::haxe::Log_obj::trace(this->atlas,hx::SourceInfo(HX_CSTRING("Main.hx"),35,HX_CSTRING("com.sync.xmlclonverter.Main"),HX_CSTRING("init")));
		HX_STACK_LINE(36)
		::haxe::Log_obj::trace(this->scelet,hx::SourceInfo(HX_CSTRING("Main.hx"),36,HX_CSTRING("com.sync.xmlclonverter.Main"),HX_CSTRING("init")));
		HX_STACK_LINE(38)
		::native::utils::ByteArray data = ::com::sync::xmlclonverter::AtlasParse_obj::__new(this->atlas)->parse();		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(39)
		::haxe::Log_obj::trace(data,hx::SourceInfo(HX_CSTRING("Main.hx"),39,HX_CSTRING("com.sync.xmlclonverter.Main"),HX_CSTRING("init")));
		HX_STACK_LINE(40)
		::haxe::Log_obj::trace(data->length,hx::SourceInfo(HX_CSTRING("Main.hx"),40,HX_CSTRING("com.sync.xmlclonverter.Main"),HX_CSTRING("init")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,init,(void))

Void Main_obj::main( ){
{
		HX_STACK_PUSH("Main::main","com/sync/xmlclonverter/Main.hx",75);
		HX_STACK_LINE(77)
		::nme::Lib_obj::get_current()->get_stage()->set_align(::native::display::StageAlign_obj::TOP_LEFT_dyn());
		HX_STACK_LINE(78)
		::nme::Lib_obj::get_current()->get_stage()->set_scaleMode(::native::display::StageScaleMode_obj::NO_SCALE_dyn());
		HX_STACK_LINE(79)
		::nme::Lib_obj::get_current()->addChild(::com::sync::xmlclonverter::Main_obj::__new());
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
	HX_MARK_MEMBER_NAME(scelet,"scelet");
	HX_MARK_MEMBER_NAME(atlas,"atlas");
	HX_MARK_MEMBER_NAME(image,"image");
	HX_MARK_MEMBER_NAME(inited,"inited");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(scelet,"scelet");
	HX_VISIT_MEMBER_NAME(atlas,"atlas");
	HX_VISIT_MEMBER_NAME(image,"image");
	HX_VISIT_MEMBER_NAME(inited,"inited");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"added") ) { return added_dyn(); }
		if (HX_FIELD_EQ(inName,"atlas") ) { return atlas; }
		if (HX_FIELD_EQ(inName,"image") ) { return image; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scelet") ) { return scelet; }
		if (HX_FIELD_EQ(inName,"inited") ) { return inited; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onLoaderComplite") ) { return onLoaderComplite_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"atlas") ) { atlas=inValue.Cast< ::Xml >(); return inValue; }
		if (HX_FIELD_EQ(inName,"image") ) { image=inValue.Cast< ::native::utils::ByteArray >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scelet") ) { scelet=inValue.Cast< ::Xml >(); return inValue; }
		if (HX_FIELD_EQ(inName,"inited") ) { inited=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("scelet"));
	outFields->push(HX_CSTRING("atlas"));
	outFields->push(HX_CSTRING("image"));
	outFields->push(HX_CSTRING("inited"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("added"),
	HX_CSTRING("onLoaderComplite"),
	HX_CSTRING("init"),
	HX_CSTRING("scelet"),
	HX_CSTRING("atlas"),
	HX_CSTRING("image"),
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.xmlclonverter.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

} // end namespace com
} // end namespace sync
} // end namespace xmlclonverter
