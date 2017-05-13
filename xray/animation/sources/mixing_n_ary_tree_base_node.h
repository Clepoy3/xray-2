////////////////////////////////////////////////////////////////////////////
//	Created		: 03.03.2010
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2010
////////////////////////////////////////////////////////////////////////////

#ifndef N_ARY_TREE_BASE_NODE_H_INCLUDED
#define N_ARY_TREE_BASE_NODE_H_INCLUDED

#include "mixing_debug.h"

namespace xray {
namespace animation {
namespace mixing {

struct n_ary_tree_visitor;
struct n_ary_tree_double_dispatcher;
class n_ary_tree_animation_node;
class n_ary_tree_weight_node;
class n_ary_tree_addition_node;
class n_ary_tree_subtraction_node;
class n_ary_tree_multiplication_node;
class n_ary_tree_transition_node;

extern u32 g_n_ary_tree_node_constructors;
extern u32 g_n_ary_tree_node_destructors;

struct XRAY_NOVTABLE n_ary_tree_base_node {
	inline			n_ary_tree_base_node	( );
#ifdef XRAY_ANIMATION_CHECK_CONSTRUCTORS
	inline			n_ary_tree_base_node	( n_ary_tree_base_node const& );
#endif // #ifdef XRAY_ANIMATION_CHECK_CONSTRUCTORS
	virtual			~n_ary_tree_base_node	( ) = 0;

	virtual	void	accept					( n_ary_tree_visitor& visitor ) = 0;
	virtual void	accept					( n_ary_tree_double_dispatcher& dispatcher, n_ary_tree_base_node& node ) = 0;

	virtual void	visit					( n_ary_tree_double_dispatcher& dispatcher, n_ary_tree_animation_node& node ) = 0;
	virtual void	visit					( n_ary_tree_double_dispatcher& dispatcher, n_ary_tree_weight_node& node ) = 0;
	virtual void	visit					( n_ary_tree_double_dispatcher& dispatcher, n_ary_tree_addition_node& node ) = 0;
	virtual void	visit					( n_ary_tree_double_dispatcher& dispatcher, n_ary_tree_subtraction_node& node ) = 0;
	virtual void	visit					( n_ary_tree_double_dispatcher& dispatcher, n_ary_tree_multiplication_node& node ) = 0;
	virtual void	visit					( n_ary_tree_double_dispatcher& dispatcher, n_ary_tree_transition_node& node ) = 0;
}; // struct n_ary_base_node

} // namespace mixing
} // namespace animation
} // namespace xray

#include "mixing_n_ary_tree_base_node_inline.h"

#endif // #ifndef N_ARY_TREE_BASE_NODE_H_INCLUDED