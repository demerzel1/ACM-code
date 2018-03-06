#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>//std::less<>
using namespace __gnu_pbds;

tree<
int,			/* key type */
null_type,		/* value type */
std::less<int>,	/* comparison */
rb_tree_tag,	/* for having an rb tree */
tree_order_statistics_node_update> example;

/*
Mapped:如果想改成set，只需要将第二个参数Mapped改为null_type
(g++4.4.0及以下应使用null_mapped_type）
Tag:可以是rb_tree_tag，splay_tree_tag，ov_tree_tag
Node_Update:空,也可用pb_ds自带的tree_order_statistics_node_update

const_iterator 
find_by_order(size_type order)
需要Node_Update，返回该tree中第order+1小的元素的迭代器，找不到返回end()

size_type 
order_of_key(key_const_reference r_key)
需要Node_Update，返回该tree中比r_key小的元素的个数

void 
join(tree &other) 
把other中所有元素移动到*this上（值域不能相交，否则抛出异常）

void 
split(key_const_reference r_key, tree &other) 
清空other，然后把*this中所有大于r_key的元素移动到other
*/