/**
 * @file head_finder.h
 * @author Chase Geigle
 *
 * All files in META are released under the MIT license. For more details,
 * consult the file LICENSE in the root of the project.
 */

#ifndef META_PARSER_HEAD_FINDER_H_
#define META_PARSER_HEAD_FINDER_H_

#include <unordered_map>

#include "meta.h"
#include "parser/trees/visitors/visitor.h"
#include "util/shim.h"

namespace meta
{
namespace parser
{

struct head_rule
{
    virtual uint64_t find_head(const internal_node&) const = 0;
    virtual ~head_rule() = default;
};

/**
 * A visitor that annotates the internal nodes of parse trees with their
 * head constituents/lexicons. This follows the head finding rules given in
 * Michael Collins' thesis and has been designed only for English using
 * Penn Treebank annotations.
 *
 * @see http://www.cs.columbia.edu/~mcollins/publications.html
 */
class head_finder : public visitor<void>
{
  public:
    using rule_table
        = std::unordered_map<class_label, std::unique_ptr<head_rule>>;

    head_finder();
    head_finder(rule_table&& table);
    void operator()(leaf_node&) override;
    void operator()(internal_node&) override;

  private:
    rule_table rules_;
};
}
}

#endif
