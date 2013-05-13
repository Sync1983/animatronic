#ifndef INCLUDED_com_sync_xmlclonverter_Main
#define INCLUDED_com_sync_xmlclonverter_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS3(com,sync,xmlclonverter,Main)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace com{
namespace sync{
namespace xmlclonverter{


class Main_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual Void added( Dynamic e);
		Dynamic added_dyn();

		virtual Void onLoaderComplite( ::native::events::Event event);
		Dynamic onLoaderComplite_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		::Xml scelet; /* REM */ 
		::Xml atlas; /* REM */ 
		::native::utils::ByteArray image; /* REM */ 
		bool inited; /* REM */ 
		static Void main( );
		static Dynamic main_dyn();

};

} // end namespace com
} // end namespace sync
} // end namespace xmlclonverter

#endif /* INCLUDED_com_sync_xmlclonverter_Main */ 
