// Copyright (c) 2019 Pantor. All rights reserved.

#ifndef INCLUDE_INJA_NODE_HPP_
#define INCLUDE_INJA_NODE_HPP_

#include <string>
#include <utility>

#include <nlohmann/json.hpp>

#include "string_view.hpp"

namespace inja {

using json = nlohmann::json;

struct Node {
  enum class Op : uint8_t {
    Nop,
    // print StringRef (always immediate)
    PrintText,
    // print value
    PrintValue,
    // push value onto stack (always immediate)
    Push,

    // builtin functions
    // result is pushed to stack
    // args specify number of arguments
    // all functions can take their "last" argument either immediate
    // or popped off stack (e.g. if immediate, it's like the immediate was
    // just pushed to the stack)
    Not,
    And,
    Or,
    In,
    Equal,
    Greater,
    GreaterEqual,
    Less,
    LessEqual,
    At,
    Different,
    DivisibleBy,
    Even,
    First,
    Float,
    Int,
    Last,
    Length,
    Lower,
    Max,
    Min,
    Odd,
    Range,
    Result,
    Round,
    Sort,
    Upper,
    Exists,
    ExistsInObject,
    IsBoolean,
    IsNumber,
    IsInteger,
    IsFloat,
    IsObject,
    IsArray,
    IsString,
    Default,

    // include another template
    // value is the template name
    Include,

    // callback function
    // str is the function name (this means it cannot be a lookup)
    // args specify number of arguments
    // as with builtin functions, "last" argument can be immediate
    Callback,

    // unconditional jump
    // args is the index of the node to jump to.
    Jump,

    // conditional jump
    // value popped off stack is checked for truthyness
    // if false, args is the index of the node to jump to.
    // if true, no action is taken (falls through)
    ConditionalJump,

    // start loop
    // value popped off stack is what is iterated over
    // args is index of node after end loop (jumped to if iterable is empty)
    // immediate value is key name (for maps)
    // str is value name
    StartLoop,

    // end a loop
    // args is index of the first node in the loop body
    EndLoop,
  };

  enum Flag {
    // location of value for value-taking ops (mask)
    ValueMask = 0x03,
    // pop value off stack
    ValuePop = 0x00,
    // value is immediate rather than on stack
    ValueImmediate = 0x01,
    // lookup immediate str (dot notation)
    ValueLookupDot = 0x02,
    // lookup immediate str (json pointer notation)
    ValueLookupPointer = 0x03,
  };

  Op op {Op::Nop};
  uint32_t args : 30;
  uint32_t flags : 2;

  json value;
  std::string str;
  size_t pos;

  explicit Node(Op op, unsigned int args, size_t pos) : op(op), args(args), flags(0), pos(pos) {}
  explicit Node(Op op, nonstd::string_view str, unsigned int flags, size_t pos) : op(op), args(0), flags(flags), str(str), pos(pos) {}
  explicit Node(Op op, json &&value, unsigned int flags, size_t pos) : op(op), args(0), flags(flags), value(std::move(value)), pos(pos) {}
};




class NodeVisitor;
class BlockNode;
class TextNode;


class AstNode {
public:
  virtual void accept(NodeVisitor&) = 0;
  virtual std::string evalString() = 0;
};

class NodeVisitor {
public:
  virtual std::string visit(BlockNode& node);
  virtual std::string visit(TextNode& node);
};

class BlockNode : AstNode {
  std::vector<std::shared_ptr<AstNode>> elements;

public:
  void accept(NodeVisitor& v) {
    v.visit(*this);
  }

  std::string evalString() {
    return elements[0]->evalString();
  }
};

class StatementNode : AstNode {

};

class IfStatementNode : AstNode {
public:
  virtual 
}

class TextNode : AstNode {
  std::string content;

public:
  void accept(NodeVisitor& v) {
    v.visit(*this);
  }

  std::string evalString() {
    return content;
  }
};

inline std::string NodeVisitor::visit(BlockNode& node) {
  return node.evalString();
}

inline std::string NodeVisitor::visit(TextNode& node) {
  return node.evalString();
}



} // namespace inja

#endif // INCLUDE_INJA_NODE_HPP_
