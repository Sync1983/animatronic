#ifndef INCLUDED_com_sync_bones2_visual_Bone
#define INCLUDED_com_sync_bones2_visual_Bone

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS4(com,sync,bones2,visual,Bone)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(native,display,Bitmap)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Stage)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace sync{
namespace bones2{
namespace visual{


class HXCPP_CLASS_ATTRIBUTES  Bone_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Bone_obj OBJ_;
		Bone_obj();
		Void __construct(int index,::native::display::BitmapData texture,::haxe::ds::IntMap coords);

	public:
		static hx::ObjectPtr< Bone_obj > __new(int index,::native::display::BitmapData texture,::haxe::ds::IntMap coords);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bone_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bone"); }

		virtual Void addToStage( int x,int y,::native::display::Stage stage);
		Dynamic addToStage_dyn();

		virtual Void setupMatrix( Array< Float > boneData);
		Dynamic setupMatrix_dyn();

		::native::display::Bitmap _bmp;
		::native::display::BitmapData _bitmap;
		int _id;
		static int X;
		static int Y;
		static int skewX;
		static int skewY;
		static int scaleX;
		static int scaleY;
		static int pivotX;
		static int pivotY;
		static int z;
};

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace visual

#endif /* INCLUDED_com_sync_bones2_visual_Bone */ 
