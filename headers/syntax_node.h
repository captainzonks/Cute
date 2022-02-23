#pragma once
#include <vector>

enum class syntax_kind;

class syntax_node
{
public:
	virtual syntax_kind get_kind() const { return kind_; }

	virtual void set_kind(const syntax_kind kind) { kind_ = kind; }
	virtual std::vector<syntax_node> get_children() { return children_; }

protected:
	syntax_kind kind_{};
	std::vector<syntax_node> children_;
};
