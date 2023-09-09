package recfun

object RecFun extends RecFunInterface:

  def main(args: Array[String]): Unit =
    println("Pascal's Triangle")
    for row <- 0 to 10 do
      for col <- 0 to row do
        print(s"${pascal(col, row)} ")
      println()

  /**
   * Exercise 1
   * Returns the value of the element at column c and row r in Pascal's Triangle.
   * The function recursively calculates the value by summing the two elements above it.
   * @param c The column of the element to retrieve.
   * @param r The row of the element to retrieve.
   * @return The value of the element at column c and row r in Pascal's Triangle.
   */
  def pascal(c: Int, r: Int): Int = {
    // The first and last elements in each row are always 1.
    if c == 0 || c == r then 1 
    // The value of any other element is the sum of the two elements above it.
    else pascal(c - 1, r - 1) + pascal(c, r - 1)
  }

 
  /**
   * Exercise 2: Parentheses Balancing
   * 
   * This function takes a string of parentheses and checks if they are balanced.
   * A string is considered balanced if it consists entirely of pairs of opening/closing parentheses,
   * and for every opening parenthesis there is a corresponding closing parenthesis in the correct order.
   * 
   * @param chars a string of parentheses to check for balance
   * @return true if the string is balanced, false otherwise
   */
  /**
   * Exercise 2
   */
  def balance(chars: List[Char]): Boolean = {
    def balanceHelper(chars: List[Char], open: Int): Boolean = {
      if (chars.isEmpty) {
        if open == 0 then true
        else false
      } 
      else if (chars.head == ')') {
        if open == 0 then false
        else balanceHelper(chars.tail, open - 1)
      } 
      else if (chars.head == '(') {
        balanceHelper(chars.tail, open + 1)
      } 
      else {
        balanceHelper(chars.tail, open)
      }  
    }

    if chars.isEmpty then true
    else if chars.head == ')' then false
    else if chars.head == '(' then balanceHelper(chars.tail, 1)
    else balance(chars.tail)
  }

  /**
   * Exercise 3
   * Counts the number of unique ways to make change for a given amount of money using a list of coin denominations.
   *
   * @param money The amount of money to make change for.
   * @param coins The list of coin denominations available to make change with.
   * @return The number of unique ways to make change for the given amount of money using the given coins.
   */
  def countChange(money: Int, coins: List[Int]): Int = 
    if money < 0 then 0
    else if money == 0 then 1
    else if coins.isEmpty then 0
    else countChange(money - coins.head, coins) + countChange(money, coins.tail)
  end countChange
