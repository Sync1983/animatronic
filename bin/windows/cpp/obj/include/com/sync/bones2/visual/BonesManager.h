#ifndef INCLUDED_com_sync_bones2_visual_BonesManager
#define INCLUDED_com_sync_bones2_visual_BonesManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesAlias)
HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesArmature)
HX_DECLARE_CLASS4(com,sync,bones2,parser,BonesAtlas)
HX_DECLARE_CLASS4(com,sync,bones2,visual,BonesManager)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
namespace com{
namespace sync{
namespace bones2{
namespace visual{


class HXCPP_CLASS_ATTRIBUTES  BonesManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BonesManager_obj OBJ_;
		BonesManager_obj();
		Void __construct(::com::sync::bones2::parser::BonesAlias alias,::com::sync::bones2::parser::BonesAtlas atlas,::native::display::BitmapData texture,::com::sync::bones2::parser::BonesArmature armatures);

	public:
		static hx::ObjectPtr< BonesManager_obj > __new(::com::sync::bones2::parser::BonesAlias alias,::com::sync::bones2::parser::BonesAtlas atlas,::native::display::BitmapData texture,::com::sync::bones2::parser::BonesArmature armatures);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BonesManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BonesManager"); }

		virtual Void createBones( );
		Dynamic createBones_dyn();

		::native::display::BitmapData _bitmap;
		::com::sync::bones2::parser::BonesArmature _armatures;
		::com::sync::bones2::parser::BonesAtlas _atlas;
		::com::sync::bones2::parser::BonesAlias _alias;
		::haxe::ds::IntMap bones;
};

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace visual

#endif /* INCLUDED_com_sync_bones2_visual_BonesManager */ 
