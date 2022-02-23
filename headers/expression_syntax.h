#pragma once
#include "syntax_node.h"
#include "syntax_token.h"

class expression_syntax : public syntax_node
{
public:

	syntax_kind get_kind() const override { return kind_; }
	void set_kind(const syntax_kind kind) override { kind_ = kind; }
	std::vector<syntax_node> get_children() override { return children_; }
};
