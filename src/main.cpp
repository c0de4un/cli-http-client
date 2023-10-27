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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// DEFINES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

constexpr const int RESULT_OK = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MAIN
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main()
{
  std::cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n";
  std::cout << "Welcome to CLI Http Client v" << APPLICATION_VERSION_MAJOR << "." << APPLICATION_VERSION_MINOR << "\n";

  std::cout << "Press any key to quit . . .\n";
  std::cin.get();
  std::cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n";
  return RESULT_OK;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
