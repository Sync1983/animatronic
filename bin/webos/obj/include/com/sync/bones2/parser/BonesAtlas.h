#ifndef INCLUDED_com_sync_bones2_parser_BonesAtlas
#define INCLUDED_com_sync_bones2_parser_BonesAtlas

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesAtlas)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace com{
namespace sync{
namespace bones2{
namespace parser{


class HXCPP_CLASS_ATTRIBUTES  BonesAtlas_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BonesAtlas_obj OBJ_;
		BonesAtlas_obj();
		Void __construct(::native::utils::ByteArray byteArray);

	public:
		static hx::ObjectPtr< BonesAtlas_obj > __new(::native::utils::ByteArray byteArray);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BonesAtlas_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BonesAtlas"); }

		virtual Void _parse( );
		Dynamic _parse_dyn();

		virtual ::haxe::ds::IntMap getBoneAtlas( int boneIndex);
		Dynamic getBoneAtlas_dyn();

		::haxe::ds::IntMap _coords;
		::native::utils::ByteArray _ba;
		static int X;
		static int Y;
		static int W;
		static int H;
};

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace parser

#endif /* INCLUDED_com_sync_bones2_parser_BonesAtlas */ 
