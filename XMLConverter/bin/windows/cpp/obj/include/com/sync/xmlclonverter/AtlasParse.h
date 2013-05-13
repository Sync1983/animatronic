#ifndef INCLUDED_com_sync_xmlclonverter_AtlasParse
#define INCLUDED_com_sync_xmlclonverter_AtlasParse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS3(com,sync,xmlclonverter,AtlasParse)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace com{
namespace sync{
namespace xmlclonverter{


class AtlasParse_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AtlasParse_obj OBJ_;
		AtlasParse_obj();
		Void __construct(::Xml xml);

	public:
		static hx::ObjectPtr< AtlasParse_obj > __new(::Xml xml);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AtlasParse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AtlasParse"); }

		virtual ::native::utils::ByteArray parse( );
		Dynamic parse_dyn();

		::String _name; /* REM */ 
		::Xml _xml; /* REM */ 
};

} // end namespace com
} // end namespace sync
} // end namespace xmlclonverter

#endif /* INCLUDED_com_sync_xmlclonverter_AtlasParse */ 
