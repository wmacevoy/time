fun merge(a : DoubleArray, offset : Int, n : Int, m : Int) {
  	var i : Int = offset
    	var j : Int = offset + m
	var x = DoubleArray(n)
	var jb = n+offset;
	var ib = m+offset;
	for (k in 0 until n) {
	    var xk : Double
	    if (j == jb) {
	      xk = a[i]
	      i += 1
	    } else if (i == ib) {
	      xk = a[j]
	      j += 1
	    } else if (a[j] < a[i]) {
	      xk = a[j]
	      j += 1
	    } else {
	      xk = a[i]
	      i += 1
	    }
	    x[k] = xk
	}
	for (k in 0 until n) {
	    a[offset+k] = x[k];
	}
}


fun merge_sort(a : DoubleArray, offset : Int, n : Int) {
    if (n < 2) {
	    return;
    }
    var m : Int = n / 2;
    merge_sort(a, offset, m);
    merge_sort(a, offset + m, n - m);
    merge(a, offset, n, m);
}

fun main() {
  var n : Int = readLine()!!.toInt()
  var a : DoubleArray = DoubleArray(n)
  for (i in 0 until n) {
     a[i]=readLine()!!.toDouble()
  }
  merge_sort(a,0,n)
  println(n)
  for (i in 0 until n) {
    println(a[i])
  }
}
 