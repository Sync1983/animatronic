#ifndef INCLUDED_com_sync_bones2_parser_ParseBytes
#define INCLUDED_com_sync_bones2_parser_ParseBytes

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesAlias)
HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesArmature)
HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesAtlas)
HX_DECLARE_CLASS4(com,sync,bones2,parser,ParseBytes)
HX_DECLARE_CLASS4(com,sync,bones2,visual,BonesManager)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace com{
namespace sync{
namespace bones2{
namespace parser{


class HXCPP_CLASS_ATTRIBUTES  ParseBytes_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ParseBytes_obj OBJ_;
		ParseBytes_obj();
		Void __construct(::native::utils::ByteArray byteArray,::native::display::BitmapData texture);

	public:
		static hx::ObjectPtr< ParseBytes_obj > __new(::native::utils::ByteArray byteArray,::native::display::BitmapData texture);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ParseBytes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ParseBytes"); }

		virtual Void _parse( );
		Dynamic _parse_dyn();

		::native::display::BitmapData _bitmap;
		::native::utils::ByteArray _ba;
		::com::sync::bones2::visual::BonesManager bonesManager;
		::com::sync::bones2::parser::BonesArmature armatures;
		::com::sync::bones2::parser::BonesAtlas atlas;
		::com::sync::bones2::parser::BonesAlias alias;
};

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace parser

#endif /* INCLUDED_com_sync_bones2_parser_ParseBytes */ 
