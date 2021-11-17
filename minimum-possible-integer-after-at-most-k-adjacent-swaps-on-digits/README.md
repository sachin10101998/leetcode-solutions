<h2>1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits</h2><h3>Hard</h3><hr><div><p>Given a string <code>num</code> representing <strong>the digits</strong> of&nbsp;a very large integer and an integer <code>k</code>.</p>

<p>You are allowed to swap any two adjacent digits of the integer <strong>at most</strong> <code>k</code> times.</p>

<p>Return <em>the minimum integer</em> you can obtain also as a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/17/q4_1.jpg" style="width: 500px; height: 40px;">
<pre><strong>Input:</strong> num = "4321", k = 4
<strong>Output:</strong> "1342"
<strong>Explanation:</strong> The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "100", k = 1
<strong>Output:</strong> "010"
<strong>Explanation:</strong> It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "36789", k = 1000
<strong>Output:</strong> "36789"
<strong>Explanation:</strong> We can keep the number without any swaps.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> num = "22", k = 22
<strong>Output:</strong> "22"
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> num = "9438957234785635408", k = 23
<strong>Output:</strong> "0345989723478563548"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 30000</code></li>
	<li><code>num</code> contains <strong>digits</strong> only and doesn't have <strong>leading zeros</strong>.</li>
	<li><code>1 &lt;= k &lt;= 10^9</code></li>
</ul>
</div>