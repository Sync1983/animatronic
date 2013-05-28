package com.sync.xmlclonverter;
import nme.Vector;

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
        var bone:Xml = XMLFinder.findNodeByName(node, _boneName);
        if(bone!=null)
          result.set(node.get("name"), bone);        
      }      
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
    
    function constructMovieData(data:Xml) {      
      var childrens:Iterator<Xml> = data.elements();
      var frames:Array<ByteMatrix> = new Array<ByteMatrix>();
      var pos:Int = 0;
      for (frame in childrens) {
        var X:String      = frame.get('x');
        var Y:String      = frame.get('y');
        var skewX:String  = frame.get('kX');
        var skewY:String  = frame.get('kY');
        var scaleX:String = frame.get('cX');
        var scaleY:String = frame.get('cY');
        var pivotX:String = frame.get('pX');
        var pivotY:String = frame.get('pY');
        var z:String      = frame.get('z');
        var duration:String = frame.get('dr');        
        frames[pos] = new ByteMatrix(_assetId, X, Y, skewX, skewY, scaleX, scaleY, pivotX, pivotY, z, duration);
        pos += 2;        
      }
      var length:Int = frames.length;
      var i:Int = 0;
      while (i < length) {
        var m:Int = i + 1;
        if (i + 2 >= length)
          break;
        var f1:Vector<Int> = frames[i].getMatrix();
        var f2:Vector<Int> = frames[i + 2].getMatrix();
        var res:Vector<String> = ["0","1","2","3","4","5","6","7","8","9"];        
        for (j in 0...7)
          res[j] = Std.string((f1[j] - f2[j]) / (f1[9] * 100));          
        res[8] = Std.string(f1[8]);
        res[9] = "1";
        frames[m] = new ByteMatrix(_assetId, res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7], res[8], "1");
        i += 2;
      }
      trace(frames);
    }
    
    function parseBoneData():Void {
      _assetId = Lambda.indexOf(_atlas.alias, _assetName);
      //Save bone start position
      var armature:Xml = XMLFinder.findNodeNamed(_scelet, "armature");      
      if (armature != null)
        for (node in armature.elements())        
          saveStartPosition(XMLFinder.findNodeByName(node, _assetName));
        
      //Find all movies for this bone
      var movies:Map<String,Xml> = findMovies();
      for (movieName in _movies) {
        constructMovieData(movies[movieName]);
      }      
    }
    
}