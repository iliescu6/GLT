precision mediump float;                           
varying vec3 v_normal;                             
uniform samplerCube s_texture;                     
void main()                                         
{
  vec4 finalColor = textureCube( s_texture, v_normal );
  //
				// Fog computing
				//
				const float LOG2 = 1.442695;
			    float z = gl_FragCoord.z / gl_FragCoord.w;
				float fogFactor = exp2( -0.05 * 
				                   0.05 * 
								   z * 
								   z * 
								   LOG2 );
				fogFactor = clamp(fogFactor, 0.0, 1.0);
				
        gl_FragColor = mix(vec4(0.5,0.5,0.5,1.0), finalColor, fogFactor );
}                              