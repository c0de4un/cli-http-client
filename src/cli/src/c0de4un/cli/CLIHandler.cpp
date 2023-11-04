/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// HEADER
#ifndef C0DE4UN_CLI_HANDLER_HPP
  #include "CLIHandler.hpp"
#endif // !C0DE4UN_CLI_HANDLER_HPP

// Include ICommand
#include <c0de4un/cli/commands/ICommand.hxx>

// Include Help
#ifndef C0DE4UN_CLI_HELP_HPP
  #include "commands/Help.hpp"
#endif /// !C0DE4UN_CLI_HELP_HPP

// Include STL
#include <iostream>
#include <algorithm>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CLIHandler
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un::cli
{

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // FIELDS
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  CLIHandler::ptr_t CLIHandler::mInstance(nullptr);
  std::mutex        CLIHandler::mInstanceMutex;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // CONSTRUCTORS
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  CLIHandler::CLIHandler() CLI_NOEXCEPT = default;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // DESTRUCTOR
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  CLIHandler::~CLIHandler() CLI_NOEXCEPT = default;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // METHODS
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  CLIHandler::ptr_t CLIHandler::getInstance() CLI_NOEXCEPT
  {
    return mInstance;
  }

  CLIHandler::ptr_t CLIHandler::Build() CLI_NOEXCEPT
  {
    std::unique_lock<std::mutex> lock(mInstanceMutex, std::defer_lock);

    if (!mInstance.get())
    {
      try
      {
        mInstance.reset(new CLIHandler());
      }
      catch (...)
      {
        // void
      }
    }

    return mInstance;
  }

  void CLIHandler::Destroy() CLI_NOEXCEPT
  {
    std::unique_lock<std::mutex> lock(mInstanceMutex, std::defer_lock);

    mInstance = nullptr;
  }

  void CLIHandler::handleArgs(const int argc, char *argv[]) const CLI_NOEXCEPT
  {
    if (argc < 2)
    {
      return;
    }

    for (int argIndex = 1; argIndex < argc; argIndex++)
    {
      handleArg(argIndex, argv, argc);
    }
  }

  void CLIHandler::parseInput(const std::string& _rawInput) const CLI_NOEXCEPT
  {
    if (_rawInput.empty() || _rawInput == "help")
    {
      runHelp();
    }
  }

  void CLIHandler::runHelp() const CLI_NOEXCEPT
  {
    std::shared_ptr<ICommand> _cmd(static_cast<ICommand*>(new Help()));
    handleCommand(_cmd);
  }

  void CLIHandler::handleArg(int &argIndex, char *argv[], const int argsCount) const CLI_NOEXCEPT
  {
    std::string argKey(argv[argIndex]);
    std::transform(argKey.begin(), argKey.end(), argKey.begin(), ::tolower);

    runHelp();
  }

  void CLIHandler::handleCommand(CLIHandler::cmd_ptr &pCommand) const CLI_NOEXCEPT
  {
    pCommand->Run();
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
