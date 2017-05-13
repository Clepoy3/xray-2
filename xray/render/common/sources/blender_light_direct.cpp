////////////////////////////////////////////////////////////////////////////
//	Created		: 24.03.2009
//	Author		: Mykhailo Parfeniuk
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "blender_light_direct.h"

namespace xray {
namespace render {


void blender_light_direct::compile(blender_compiler& compiler, const blender_compilation_options& options)
{
	XRAY_UNREFERENCED_PARAMETER	( options );

	shader_defines_list	defines;
	make_defines(defines);

	bool		b_hw_smap = true;//RImplementation.o.HW_smap;
	bool		b_hw_pcf  = false;//RImplementation.o.HW_smap_PCF;
	bool		blend = FALSE;	//RImplementation.o.fp16_blend;
	D3DBLEND	dest = blend ? D3DBLEND_ONE : D3DBLEND_ZERO;

//	if (RImplementation.o.sunfilter)	{ blend = FALSE; dest = D3DBLEND_ZERO; }

	compiler.begin_technique(/*SE_SUN_NEAR*/)
		.begin_pass("stub_notransform_2uv", "accum_sun_materials", defines)
			.set_z_test(FALSE, D3DCMP_GREATEREQUAL)
			.set_alpha_blend(blend, D3DBLEND_ONE, dest)
			.def_sampler_rtf("s_position",    r2_rt_p)
			.def_sampler_rtf("s_normal",      r2_rt_n)
			.def_sampler_rtf("s_accumulator", r2_rt_accum) //used when fp16 blend is not available
			.def_sampler_clw("s_material",    r2_material)
			.def_sampler("s_lmap",			  r2_sunmask);
			if (b_hw_smap)
			{
				if (b_hw_pcf)
					compiler.def_sampler_clf("s_smap", r2_rt_smap_depth);
				else			{
					compiler.def_sampler_rtf("s_smap", r2_rt_smap_depth);
				}
			}
			jitter(compiler);
		compiler.end_pass()
	.end_technique();

	compiler.begin_technique(/*SE_SUN_FAR*/)
		.begin_pass("stub_notransform_2uv", "accum_sun_far", defines)
			.set_z_test(FALSE, D3DCMP_LESSEQUAL)
			.set_alpha_blend(blend, D3DBLEND_ONE, dest)
			.def_sampler_rtf("s_position",    r2_rt_p)
			.def_sampler_rtf("s_normal",      r2_rt_n)
			.def_sampler_rtf("s_accumulator", r2_rt_accum) //used when fp16 blend is not available
			.def_sampler_clw("s_material",    r2_material)
			.def_sampler("s_lmap",			  r2_sunmask);
			if (b_hw_smap)
			{
				if (b_hw_pcf)
					compiler.def_sampler_clf("s_smap", r2_rt_smap_depth);
				else			{
					compiler.def_sampler_rtf("s_smap", r2_rt_smap_depth);
				}
			}
			jitter(compiler);
		compiler.end_pass()
	.end_technique();

	//BOOL	b_HW_smap		= RImplementation.o.HW_smap;
	//BOOL	b_HW_PCF		= RImplementation.o.HW_smap_PCF;
	//BOOL		blend		= FALSE;	//RImplementation.o.fp16_blend;
	//D3DBLEND	dest		= blend?D3DBLEND_ONE:D3DBLEND_ZERO;
	//if (RImplementation.o.sunfilter)	{ blend = FALSE; dest = D3DBLEND_ZERO; }

	//switch (C.iElement)
	//{
	//case SE_SUN_NEAR:		// near pass - enable Z-test to perform depth-clipping
	//	C.r_Pass			("null",			"accum_sun_near",	false,	TRUE,	FALSE,blend,D3DBLEND_ONE,dest);
	//	C.PassSET_ZB		(TRUE,FALSE,TRUE	);	// force inverted Z-Buffer
	//	C.r_Sampler_rtf		("s_position",		r2_RT_P			);
	//	C.r_Sampler_rtf		("s_normal",		r2_RT_N			);
	//	C.r_Sampler_clw		("s_material",		r2_material		);
	//	C.r_Sampler	("s_mat_params", r2_mat_parms, false, D3DTADDRESS_WRAP, D3DTEXF_LINEAR, D3DTEXF_NONE, D3DTEXF_LINEAR);
	//	C.r_Sampler_rtf		("s_accumulator",	r2_RT_accum		);
	//	C.r_Sampler			("s_lmap",			r2_sunmask		);
	//	if (b_HW_smap)		{
	//		if (b_HW_PCF)	C.r_Sampler_clf		("s_smap",r2_RT_smap_depth	);
	//		else			{
	//			C.r_Sampler_rtf		("s_smap",r2_RT_smap_depth	);
	//		}
	//	}
	//	else				C.r_Sampler_rtf		("s_smap",r2_RT_smap_surf	);
	//	jitter				(C);
	//	C.r_End				();
	//	break;
	//case SE_SUN_FAR:		// far pass, only stencil clipping performed
	//	C.r_Pass			("null",			"accum_sun_far",	false,	TRUE,	FALSE,blend,D3DBLEND_ONE,dest);
	//	C.r_Sampler_rtf		("s_position",		r2_RT_P			);
	//	C.r_Sampler_rtf		("s_normal",		r2_RT_N			);
	//	C.r_Sampler_clw		("s_material",		r2_material		);
	//	C.r_Sampler	("s_mat_params", r2_mat_parms, false, D3DTADDRESS_WRAP, D3DTEXF_LINEAR, D3DTEXF_NONE, D3DTEXF_LINEAR);
	//	C.r_Sampler_rtf		("s_accumulator",	r2_RT_accum		);
	//	C.r_Sampler			("s_lmap",			r2_sunmask		);
	//	if (b_HW_smap)		{
	//		if (b_HW_PCF)	C.r_Sampler_clf		("s_smap",r2_RT_smap_depth	);
	//		else			C.r_Sampler_rtf		("s_smap",r2_RT_smap_depth	);
	//	}
	//	else				C.r_Sampler_rtf		("s_smap",r2_RT_smap_surf	);
	//	jitter				(C);
	//	C.r_End				();
	//	break;
	//case SE_SUN_LUMINANCE:	// luminance pass
	//	C.r_Pass			("null",			"accum_sun",		false,	FALSE,	FALSE);
	//	C.r_Sampler_rtf		("s_position",		r2_RT_P			);
	//	C.r_Sampler_rtf		("s_normal",		r2_RT_N			);
	//	C.r_Sampler_clw		("s_material",		r2_material		);
	//	C.r_Sampler	("s_mat_params", r2_mat_parms, false, D3DTADDRESS_WRAP, D3DTEXF_LINEAR, D3DTEXF_NONE, D3DTEXF_LINEAR);
	//	C.r_Sampler_clf		("s_smap",			r2_RT_generic0	);
	//	jitter				(C);
	//	C.r_End				();
	//	break;
	//}
}

} // namespace render 
} // namespace xray 
