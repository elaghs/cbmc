/*******************************************************************\

Module:

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/


#ifndef CPROVER_UTIL_BYTE_OPERATORS_H
#define CPROVER_UTIL_BYTE_OPERATORS_H

/*! \file util/byte_operators.h
 * \brief Expression classes for byte-level operators
 *
 * \author Daniel Kroening <kroening@kroening.com>
 * \date   Sun Jul 31 21:54:44 BST 2011
*/

#include "std_expr.h"

/*! \brief TO_BE_DOCUMENTED
*/
class byte_extract_exprt:public binary_exprt
{
public:
  explicit byte_extract_exprt(irep_idt _id):binary_exprt(_id)
  {
  }

  explicit byte_extract_exprt(irep_idt _id, const typet &_type):
    binary_exprt(_id, _type)
  {
  }

  byte_extract_exprt(
    irep_idt _id,
    const exprt &_op, const exprt &_offset, const typet &_type):
    binary_exprt(_id, _type)
  {
    op()=_op;
    offset()=_offset;
  }

  exprt &op() { return op0(); }
  exprt &offset() { return op1(); }

  const exprt &op() const { return op0(); }
  const exprt &offset() const { return op1(); }
};

inline const byte_extract_exprt &to_byte_extract_expr(const exprt &expr)
{
  assert(expr.operands().size()==2);
  return static_cast<const byte_extract_exprt &>(expr);
}

inline byte_extract_exprt &to_byte_extract_expr(exprt &expr)
{
  assert(expr.operands().size()==2);
  return static_cast<byte_extract_exprt &>(expr);
}

irep_idt byte_extract_id();
irep_idt byte_update_id();

/*! \brief TO_BE_DOCUMENTED
*/
class byte_extract_little_endian_exprt:public byte_extract_exprt
{
public:
  byte_extract_little_endian_exprt():
    byte_extract_exprt(ID_byte_extract_little_endian)
  {
  }
};

inline const byte_extract_little_endian_exprt
  &to_byte_extract_little_endian_expr(const exprt &expr)
{
  assert(expr.id()==ID_byte_extract_little_endian && expr.operands().size()==2);
  return static_cast<const byte_extract_little_endian_exprt &>(expr);
}

inline byte_extract_little_endian_exprt
  &to_byte_extract_little_endian_expr(exprt &expr)
{
  assert(expr.id()==ID_byte_extract_little_endian && expr.operands().size()==2);
  return static_cast<byte_extract_little_endian_exprt &>(expr);
}

/*! \brief TO_BE_DOCUMENTED
*/
class byte_extract_big_endian_exprt:public byte_extract_exprt
{
public:
  byte_extract_big_endian_exprt():
    byte_extract_exprt(ID_byte_extract_big_endian)
  {
  }

  byte_extract_big_endian_exprt(
    const exprt &_op, const exprt &_offset, const typet &_type):
    byte_extract_exprt(ID_byte_extract_big_endian, _op, _offset, _type)
  {
  }
};

inline const byte_extract_big_endian_exprt
  &to_byte_extract_big_endian_expr(const exprt &expr)
{
  assert(expr.id()==ID_byte_extract_big_endian && expr.operands().size()==2);
  return static_cast<const byte_extract_big_endian_exprt &>(expr);
}

inline byte_extract_big_endian_exprt
  &to_byte_extract_big_endian_expr(exprt &expr)
{
  assert(expr.id()==ID_byte_extract_big_endian && expr.operands().size()==2);
  return static_cast<byte_extract_big_endian_exprt &>(expr);
}

/*! \brief TO_BE_DOCUMENTED
*/
class byte_update_exprt:public exprt
{
public:
  explicit byte_update_exprt(irep_idt _id):exprt(_id)
  {
    operands().resize(3);
  }

  byte_update_exprt(irep_idt _id, const typet &_type):
    exprt(_id, _type)
  {
    operands().resize(3);
  }

  byte_update_exprt(
    irep_idt _id,
    const exprt &_op, const exprt &_offset, const exprt &_value):
    exprt(_id, _op.type())
  {
    copy_to_operands(_op, _offset, _value);
  }

  exprt &op() { return op0(); }
  exprt &offset() { return op1(); }
  exprt &value() { return op2(); }

  const exprt &op() const { return op0(); }
  const exprt &offset() const { return op1(); }
  const exprt &value() const { return op2(); }
};

inline const byte_update_exprt &to_byte_update_expr(const exprt &expr)
{
  assert(expr.operands().size()==3);
  return static_cast<const byte_update_exprt &>(expr);
}

inline byte_update_exprt &to_byte_update_expr(exprt &expr)
{
  assert(expr.operands().size()==3);
  return static_cast<byte_update_exprt &>(expr);
}

/*! \brief TO_BE_DOCUMENTED
*/
class byte_update_little_endian_exprt:public byte_update_exprt
{
public:
  byte_update_little_endian_exprt():
    byte_update_exprt(ID_byte_update_little_endian)
  {
  }

  byte_update_little_endian_exprt(
    const exprt &_op, const exprt &_offset, const exprt &_value):
    byte_update_exprt(ID_byte_update_little_endian, _op, _offset, _value)
  {
  }
};

inline const byte_update_little_endian_exprt
  &to_byte_update_little_endian_expr(const exprt &expr)
{
  assert(expr.id()==ID_byte_update_little_endian && expr.operands().size()==3);
  return static_cast<const byte_update_little_endian_exprt &>(expr);
}

inline byte_update_little_endian_exprt
  &to_byte_update_little_endian_expr(exprt &expr)
{
  assert(expr.id()==ID_byte_update_little_endian && expr.operands().size()==3);
  return static_cast<byte_update_little_endian_exprt &>(expr);
}

/*! \brief TO_BE_DOCUMENTED
*/
class byte_update_big_endian_exprt:public byte_update_exprt
{
public:
  byte_update_big_endian_exprt():
    byte_update_exprt(ID_byte_update_big_endian)
  {
  }

  byte_update_big_endian_exprt(
    const exprt &_op, const exprt &_offset, const exprt &_value):
    byte_update_exprt(ID_byte_update_big_endian, _op, _offset, _value)
  {
  }
};

inline const byte_update_big_endian_exprt
  &to_byte_update_big_endian_expr(const exprt &expr)
{
  assert(expr.id()==ID_byte_update_big_endian && expr.operands().size()==3);
  return static_cast<const byte_update_big_endian_exprt &>(expr);
}

inline byte_update_big_endian_exprt
  &to_byte_update_big_endian_expr(exprt &expr)
{
  assert(expr.id()==ID_byte_update_big_endian && expr.operands().size()==3);
  return static_cast<byte_update_big_endian_exprt &>(expr);
}

#endif // CPROVER_UTIL_BYTE_OPERATORS_H
