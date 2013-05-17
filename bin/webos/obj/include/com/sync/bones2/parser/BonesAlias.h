#ifndef INCLUDED_com_sync_bones2_parser_BonesAlias
#define INCLUDED_com_sync_bones2_parser_BonesAlias

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesAlias)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace com{
namespace sync{
namespace bones2{
namespace parser{


class HXCPP_CLASS_ATTRIBUTES  BonesAlias_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BonesAlias_obj OBJ_;
		BonesAlias_obj();
		Void __construct(::native::utils::ByteArray byteArray);

	public:
		static hx::ObjectPtr< BonesAlias_obj > __new(::native::utils::ByteArray byteArray);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BonesAlias_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BonesAlias"); }

		virtual Void _parse( );
		Dynamic _parse_dyn();

		virtual ::haxe::ds::IntMap getNames( );
		Dynamic getNames_dyn();

		::haxe::ds::IntMap _names;
		::native::utils::ByteArray _ba;
};

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace parser

#endif /* INCLUDED_com_sync_bones2_parser_BonesAlias */ 
