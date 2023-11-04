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
#include "Help.hpp"

// Include STL
#include <iostream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Help
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un::cli
{

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // CONSTRUCTOR
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  Help::Help() CLI_NOEXCEPT = default;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // DESTRUCTOR
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  Help::~Help() CLI_NOEXCEPT = default;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // PUBLIC.METHODS.ICOMMAND
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  std::string Help::getError() const noexcept
  {
    return "";
  }

  bool Help::Run() CLI_NOEXCEPT
  {
    std::cout
      << "Commands:\n"
      << "help <command> - retrieve details command description\n"
      << "get - send request with GET-method\n"
      << "post - send request with GET-method\n";

    return true;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} /// c0de4un::cli

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
