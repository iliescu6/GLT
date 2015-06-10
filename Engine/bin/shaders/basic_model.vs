attribute vec3 a_position;  
attribute vec2 a_texCoord;  
attribute vec3 a_normalCoord;
uniform mat4 u_mvpMatrix;  
varying vec2 v_texCoord;
    
void main()                 
 {                            
 gl_Position = u_mvpMatrix * vec4(a_position,1.0); 
 v_texCoord = a_texCoord;  
 }     