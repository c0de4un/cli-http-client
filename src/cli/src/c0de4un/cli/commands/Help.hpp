/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef C0DE4UN_CLI_HELP_HPP
#define C0DE4UN_CLI_HELP_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include ICommand
#include <c0de4un/cli/commands/ICommand.hxx>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace c0de4un::cli
{

  class Help final : public ICommand
  {

  public:

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // DELETED
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    Help(const Help&) noexcept            = delete;
    Help& operator=(const Help&) noexcept = delete;
    Help(Help&&) noexcept                 = delete;
    Help& operator=(Help&&) noexcept      = delete;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // CONSTRUCTOR
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    explicit Help() CLI_NOEXCEPT;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // DESTRUCTOR
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ~Help() CLI_NOEXCEPT override;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // METHODS.ICOMMAND
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    std::string getError() const noexcept override;

    bool Run() CLI_NOEXCEPT override;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  }; /// c0de4un::cli::Help

} /// c0de4un::cli

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !C0DE4UN_CLI_HELP_HPP
