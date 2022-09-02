#pragma once

#include <functional>
#include <ostream>  // more considerate than <iosfwd>
#include <string_view>

namespace datadog {
namespace tracing {

struct Error;

class Logger {
 public:
  using LogFunc = std::function<void(std::ostream&)>;

  virtual ~Logger() {}

  virtual void log_error(const LogFunc&) = 0;
  virtual void log_startup(const LogFunc&) = 0;

  virtual void log_error(const Error&);
  virtual void log_error(std::string_view);
};

}  // namespace tracing
}  // namespace datadog
