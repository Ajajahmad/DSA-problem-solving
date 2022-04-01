# Lucky Number
## Easy 
<div class="problem-statement">
                <p></p><p style="text-align:justify"><span style="font-size:18px">A n digit number has n*(n+1)/2 sub-numbers.&nbsp; For example, all possible sub-numbers of <strong>975</strong> are <strong>9 7 5 97 75 975</strong>. A number is called Lucky if all sub-numbers have different digit product.&nbsp; Digit product of a number is product of its digits.&nbsp;&nbsp; </span></p>

<p style="text-align:justify"><span style="font-size:18px">For example, the number <strong>23</strong> is Lucky.&nbsp; Subsequences of it are <strong>2</strong>,<strong> 3</strong> and <strong>23</strong> and digit products are <strong>2</strong>, <strong>3 </strong>and <strong>6 </strong>respectively (All digit products are different). <strong>975</strong> is also lucky. Print 1 if given Number is Lucky else Print 0.</span></p>

<p style="text-align:justify">&nbsp;</p>

<p style="text-align:justify"><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
<strong>N = </strong>324
<strong>Output:</strong>
1
<strong>Explanation:</strong>
All subsequences form different Digit
Products. So, Output is 1.</span></pre>

<p style="text-align:justify"><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
<strong>N = </strong>323
<strong>Output:</strong>
0
<strong>Explanation:</strong>
Subsequences 32, and 23 form same
Digit Product, i.e, 6. So, Output is 0.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>isLuckyOrNot()</strong> which takes an Integer N as input and returns the answer.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O((Number of Digits)<sup>2</sup>)<br>
<strong>Expected Auxiliary Space:</strong> O(Number of Digits)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 &lt;= N &lt;= 10<sup>18</sup></span></p>
 <p></p>
            </div>