#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_BonesAlias
#include <com/sync/bones2/parser/BonesAlias.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_BonesArmature
#include <com/sync/bones2/parser/BonesArmature.h>
#endif
#ifndef INCLUDED_com_sync_bones2_parser_BonesAtlas
#include <com/sync/bones2/parser/BonesAtlas.h>
#endif
#ifndef INCLUDED_com_sync_bones2_visual_Bone
#include <com/sync/bones2/visual/Bone.h>
#endif
#ifndef INCLUDED_com_sync_bones2_visual_BonesManager
#include <com/sync/bones2/visual/BonesManager.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
namespace com{
namespace sync{
namespace bones2{
namespace visual{

Void BonesManager_obj::__construct(::com::sync::bones2::parser::BonesAlias alias,::com::sync::bones2::parser::BonesAtlas atlas,::native::display::BitmapData texture,::com::sync::bones2::parser::BonesArmature armatures)
{
HX_STACK_PUSH("BonesManager::new","com/sync/bones2/visual/BonesManager.hx",19);
{
	HX_STACK_LINE(20)
	this->_alias = alias;
	HX_STACK_LINE(21)
	this->_atlas = atlas;
	HX_STACK_LINE(22)
	this->_bitmap = texture;
	HX_STACK_LINE(23)
	this->_armatures = armatures;
	HX_STACK_LINE(24)
	this->createBones();
}
;
	return null();
}

BonesManager_obj::~BonesManager_obj() { }

Dynamic BonesManager_obj::__CreateEmpty() { return  new BonesManager_obj; }
hx::ObjectPtr< BonesManager_obj > BonesManager_obj::__new(::com::sync::bones2::parser::BonesAlias alias,::com::sync::bones2::parser::BonesAtlas atlas,::native::display::BitmapData texture,::com::sync::bones2::parser::BonesArmature armatures)
{  hx::ObjectPtr< BonesManager_obj > result = new BonesManager_obj();
	result->__construct(alias,atlas,texture,armatures);
	return result;}

Dynamic BonesManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BonesManager_obj > result = new BonesManager_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void BonesManager_obj::createBones( ){
{
		HX_STACK_PUSH("BonesManager::createBones","com/sync/bones2/visual/BonesManager.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_LINE(28)
		::haxe::ds::IntMap names = this->_alias->getNames();		HX_STACK_VAR(names,"names");
		HX_STACK_LINE(29)
		int itemsCount = ::Lambda_obj::count(names,null());		HX_STACK_VAR(itemsCount,"itemsCount");
		HX_STACK_LINE(30)
		::haxe::ds::IntMap result = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(32)
		{
			HX_STACK_LINE(32)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(32)
			while(((_g < itemsCount))){
				HX_STACK_LINE(32)
				int index = (_g)++;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(33)
				::haxe::ds::IntMap coords = this->_atlas->getBoneAtlas(index);		HX_STACK_VAR(coords,"coords");
				HX_STACK_LINE(34)
				::com::sync::bones2::visual::Bone bone = ::com::sync::bones2::visual::Bone_obj::__new(index,this->_bitmap,coords);		HX_STACK_VAR(bone,"bone");
				HX_STACK_LINE(35)
				bone->setupMatrix(this->_armatures->getBoneParams(index));
				HX_STACK_LINE(36)
				::haxe::Log_obj::trace(((HX_CSTRING("Name: ") + names->get(index)) + ::Std_obj::string(this->_armatures->getBoneParams(index))),hx::SourceInfo(HX_CSTRING("BonesManager.hx"),36,HX_CSTRING("com.sync.bones2.visual.BonesManager"),HX_CSTRING("createBones")));
				HX_STACK_LINE(37)
				{
					HX_STACK_LINE(37)
					result->set(((itemsCount - index) - (int)1),bone);
					HX_STACK_LINE(37)
					bone;
				}
			}
		}
		HX_STACK_LINE(39)
		this->bones = result;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BonesManager_obj,createBones,(void))


BonesManager_obj::BonesManager_obj()
{
}

void BonesManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BonesManager);
	HX_MARK_MEMBER_NAME(_bitmap,"_bitmap");
	HX_MARK_MEMBER_NAME(_armatures,"_armatures");
	HX_MARK_MEMBER_NAME(_atlas,"_atlas");
	HX_MARK_MEMBER_NAME(_alias,"_alias");
	HX_MARK_MEMBER_NAME(bones,"bones");
	HX_MARK_END_CLASS();
}

void BonesManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_bitmap,"_bitmap");
	HX_VISIT_MEMBER_NAME(_armatures,"_armatures");
	HX_VISIT_MEMBER_NAME(_atlas,"_atlas");
	HX_VISIT_MEMBER_NAME(_alias,"_alias");
	HX_VISIT_MEMBER_NAME(bones,"bones");
}

Dynamic BonesManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bones") ) { return bones; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_atlas") ) { return _atlas; }
		if (HX_FIELD_EQ(inName,"_alias") ) { return _alias; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_bitmap") ) { return _bitmap; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_armatures") ) { return _armatures; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createBones") ) { return createBones_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BonesManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bones") ) { bones=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_atlas") ) { _atlas=inValue.Cast< ::com::sync::bones2::parser::BonesAtlas >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_alias") ) { _alias=inValue.Cast< ::com::sync::bones2::parser::BonesAlias >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_bitmap") ) { _bitmap=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_armatures") ) { _armatures=inValue.Cast< ::com::sync::bones2::parser::BonesArmature >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BonesManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_bitmap"));
	outFields->push(HX_CSTRING("_armatures"));
	outFields->push(HX_CSTRING("_atlas"));
	outFields->push(HX_CSTRING("_alias"));
	outFields->push(HX_CSTRING("bones"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createBones"),
	HX_CSTRING("_bitmap"),
	HX_CSTRING("_armatures"),
	HX_CSTRING("_atlas"),
	HX_CSTRING("_alias"),
	HX_CSTRING("bones"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BonesManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BonesManager_obj::__mClass,"__mClass");
};

Class BonesManager_obj::__mClass;

void BonesManager_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.sync.bones2.visual.BonesManager"), hx::TCanCast< BonesManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BonesManager_obj::__boot()
{
}

} // end namespace com
} // end namespace sync
} // end namespace bones2
} // end namespace visual
