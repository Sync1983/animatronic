#ifndef INCLUDED_com_sync_bones2_parser_BonesArmature
#define INCLUDED_com_sync_bones2_parser_BonesArmature

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesArmature)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace com{
namespace sync{
namespace bones2{
namespace parser{


class HXCPP_CLASS_ATTRIBUTES  BonesArmature_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BonesArmature_obj OBJ_;
		BonesArmature_obj();
		Void __construct(::native::utils::ByteArray byteArray);

	public:
		static hx::ObjectPtr< BonesArmature_obj > __new(::native::utils::ByteArray byteArray);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BonesArmature_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BonesArmature"); }

		virtual Void parse( );
		Dynamic parse_dyn();

		virtual Array< Float > getBoneParams( int atlasId);
		Dynamic getBoneParams_dyn();

		Array< ::Dynamic > _startPosition;
		int _frameRate;
		::String _name;
		::native::utils::ByteArray _ba;
};

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace parser

#endif /* INCLUDED_com_sync_bones2_parser_BonesArmature */ 
