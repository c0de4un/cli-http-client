/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef C0DE4UN_CLI_I_COMMAND_HXX
#define C0DE4UN_CLI_I_COMMAND_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include API
#include "../api.hpp"

// Include STL
#include <string>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un::cli
{

  class ICommand
  {

  public:

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // DESTRUCTOR
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    virtual ~ICommand() CLI_NOEXCEPT = default;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // METHODS
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    virtual std::string getError() const noexcept = 0;

    virtual bool Run() CLI_NOEXCEPT = 0;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  }; // c0de4un::cli::ICommand

} // c0de4un::cli
#define C0DE4UN_CLI_I_COMMAND_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !C0DE4UN_CLI_I_COMMAND_HXX
