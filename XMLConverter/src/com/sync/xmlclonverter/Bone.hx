package com.sync.xmlclonverter;

/** 
 * @author Sync
 */

class Bone
{
    private var _assetName:String;
    private var _assetId:Int;
    private var _boneName:String;
    private var _startPosition:ByteMatrix;
    private var _movies:Array<String>;
    private var _moviesData:Map <String, ByteMatrix> ;
    private var _atlas:AtlasParse;
    private var _scelet:Xml;

    public function new(assetName:String,atlas:AtlasParse,scelet:Xml) {
      _assetName = assetName;
      _atlas = atlas;
      _scelet = scelet;      
      _movies = new Array<String>();
      _moviesData = new Map <String,ByteMatrix> ();            
      parseBoneData();
    }
    
    function findMovies():Map<String,Xml> {
      var result:Map<String,Xml> = new Map<String,Xml>();      
      // Fill Movies names
      var animation:Xml = XMLFinder.findNodeNamed(_scelet,"animation");           
      
      for (node in animation.elements()) {
        _movies.push(node.get("name"));
        trace(_boneName);
        var bone:Xml = XMLFinder.findNodeByName(node, _boneName);
        if(bone!=null)
          result.set(node.get("name"), bone);        
      }
        
      trace(_movies);
      trace(result);
      return result;
    }
    
    function saveStartPosition(element:Xml):Void {      
      if (element == null)
        return;
      element = element.parent;
      _boneName = element.get('name');
      trace(_boneName);
      var X:String      = element.get('x');
      var Y:String      = element.get('y');
      var skewX:String  = element.get('kX');
      var skewY:String  = element.get('kY');
      var scaleX:String = element.get('cX');
      var scaleY:String = element.get('cY');
      var pivotX:String = element.get('pX');
      var pivotY:String = element.get('pY');
      var z:String      = element.get('z');      
      
      _startPosition = new ByteMatrix(_assetId, X, Y, skewX, skewY, scaleX, scaleY, pivotX, pivotY, z);      
    }
    
    function parseBoneData():Void {
      _assetId = Lambda.indexOf(_atlas.alias, _assetName);
      //Save bone start position
      var armature:Xml = XMLFinder.findNodeNamed(_scelet, "armature");      
      if (armature != null)
        for (node in armature.elements())        
          saveStartPosition(XMLFinder.findNodeByName(node, _assetName));
        
      //Find all movies for this bone
      findMovies();
      
    }
    
}