/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef C0DE4UN_CLI_HANDLER_HPP
#define C0DE4UN_CLI_HANDLER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include api
#ifndef C0DE4UN_CLI_API_HPP
  #include "api.hpp"
#endif /// !C0DE4UN_CLI_API_HPP

// Include STL
#include <memory>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD-DECLARATIONS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Forward-Declare ICommand
#ifndef C0DE4UN_CLI_I_COMMAND_DECL
  #define C0DE4UN_CLI_I_COMMAND_DECL
  namespace c0de4un::cli { class ICommand; }
#endif /// !C0DE4UN_CLI_I_COMMAND_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un::cli
{

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  class CLIHandler final
  {

  private:

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // ALIASES
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    using ptr_t   = std::shared_ptr<CLIHandler>;
    using cmd_ptr = std::shared_ptr<ICommand>;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // FIELDS
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    static ptr_t      mInstance;
    static std::mutex mInstanceMutex;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // CONSTRUCTOR
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    explicit CLIHandler() CLI_NOEXCEPT;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // METHODS
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    inline void runHelp() const CLI_NOEXCEPT;
    void handleCommand(cmd_ptr &pCommand) const CLI_NOEXCEPT;
    void handleArg(int &argIndex, char *argv[], const int argsCount) const CLI_NOEXCEPT;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  public:

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // DELETED
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    CLIHandler(const CLIHandler&) noexcept            = delete;
    CLIHandler& operator=(const CLIHandler&) noexcept = delete;
    CLIHandler(CLIHandler&&) noexcept                 = delete;
    CLIHandler& operator=(CLIHandler&&) noexcept      = delete;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // DESTRUCTOR
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ~CLIHandler() CLI_NOEXCEPT;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // METHODS
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    static ptr_t getInstance() CLI_NOEXCEPT;
    static ptr_t Build() CLI_NOEXCEPT;
    static void Destroy() CLI_NOEXCEPT;

    void handleArgs(const int argc, char *argv[]) const CLI_NOEXCEPT;
    void parseInput(const std::string &_rawInput) const CLI_NOEXCEPT;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  }; // c0de4un::cli::CLIHandler

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // c0de4un::cli
using _CLIHandler = c0de4un::cli::CLIHandler;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !C0DE4UN_CLI_HANDLER_HPP
