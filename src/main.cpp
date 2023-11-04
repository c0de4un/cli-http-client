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

// Include STL
#include <iostream>

// Include CLIHandler
#ifndef C0DE4UN_CLI_HANDLER_HPP
  #include <c0de4un/cli/CLIHandler.hpp>
#endif /// !C0DE4UN_CLI_HANDLER_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// DEFINES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

constexpr const int RESULT_OK = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MAIN
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(int argc, char *argv[])
{
  std::cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n";
  std::cout << "Welcome to CLI Http Client v" << APPLICATION_VERSION_MAJOR << "." << APPLICATION_VERSION_MINOR << "\n";

  auto cliHandler(
    _CLIHandler::Build()
  );

  if (argc > 1)
  {
    cliHandler->handleArgs(argc, argv);
  }
  else
  {
    std::string _cmdLine;

    while (_cmdLine != "exit" || _cmdLine != "quit" || _cmdLine != "q")
    {
      std::cout << "Enter command. To list available types \"help\"\n";
      std::cin >> _cmdLine;

      cliHandler->parseInput(_cmdLine);
    }
    
  }

  _CLIHandler::Destroy();
  std::cout << "Press any key to quit . . .\n";
  std::cin.get();
  std::cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n";
  return RESULT_OK;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
