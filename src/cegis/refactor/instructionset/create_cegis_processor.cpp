#include <cegis/instrument/literals.h>

#include <cegis/refactor/instructionset/create_cegis_processor.h>

namespace
{
class type_collectort: public const_expr_visitort
{
public:
  std::set<typet> types;

  virtual ~type_collectort()=default;

  virtual void operator()(const exprt &expr)
  {
    types.insert(expr.type());
  }
};
}

std::set<typet> collect_context_types(const goto_ranget &range)
{
  type_collectort collector;
  for (goto_programt::const_targett it(range.first); it != range.second; ++it)
    it->code.visit(collector);
  return collector.types;
}

#define CEGIS_PROCESSOR_FUNCTION_PREFIX CEGIS_PREFIX "processor_"

std::string create_cegis_processor(const std::set<typet> &state_types,
    const size_t var_slots_per_state_type, const std::set<typet> &context_types)
{
  std::string processor_name(CEGIS_PROCESSOR_FUNCTION_PREFIX);
  // TODO: Implement
  assert(false);
}
