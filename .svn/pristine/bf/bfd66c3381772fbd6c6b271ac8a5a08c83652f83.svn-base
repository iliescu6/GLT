 attribute vec4 a_position;   
 attribute vec3 a_normal;  
 uniform mat4 u_mvpMatrix;   
 uniform vec3 a_lightPos;
varying float atten; 
 varying vec3 v_normal;      
 void main()                 
 {                           
    gl_Position = u_mvpMatrix *a_position; 
    v_normal = vec3(a_position[0],a_position[1],a_position[2]);  

	vec3 vVertex = vec3(u_mvpMatrix * a_position.x);
	vec3 vLVec = a_lightPos - vVertex; 
	atten = 1.0 / (1.0 + 0.00001 * dot(vLVec, vLVec));	
 }                           