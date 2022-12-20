import java.io.*;
import java.util.*;

public class sentence {
	public static ArrayList<char[]> getWords(Scanner input) {
		StringTokenizer line = new StringTokenizer(input.nextLine());
		ArrayList<char[]> res = new ArrayList<char[]>();
		while(line.hasMoreTokens()) {
			String s = line.nextToken();
			res.add(s.toCharArray());
		}
		return res;
	}

	public static boolean cap(boolean needCap, char[] word) {
		if(needCap) {
			needCap = false;
			if('a' <= word[0] && word[0] <= 'z')
				word[0] += ('A' - 'a');
		}
		return needCap;
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int K = input.nextInt();
		ArrayList<char[]> Ns = new ArrayList<char[]>();
		ArrayList<char[]> Cs = new ArrayList<char[]>();
		ArrayList<char[]> Vs = new ArrayList<char[]>();
		ArrayList<char[]> Js = new ArrayList<char[]>();
		ArrayList<char[]> Bs = new ArrayList<char[]>();
		ArrayList<char[]> Ps = new ArrayList<char[]>();
		int Ni = 0, Ci = 0, Vi = 0, Ji = 0, Bi = 0, Pi = 0;
		for(int k = 0; k < K; ++k) {
			char part = input.next().charAt(0);
			switch(part) {
			case 'N': Ns = getWords(input); break;
			case 'C': Cs = getWords(input); break;
			case 'V': Vs = getWords(input); break;
			case 'J': Js = getWords(input); break;
			case 'B': Bs = getWords(input); break;
			case 'P': Ps = getWords(input); break;
			}
		}
		ArrayList<char[]> sentences = getWords(input);
		for(int i = 0; i < sentences.size(); ++i) {
			String beg = new String();
			String mid = new String();
			String end = new String();
			boolean needCapital = true;
			char ch1 = sentences.get(i)[0];
			switch(ch1) {
			case 'D':
				end = new String(".");
				break;
			case 'I':
				end = new String(".");
				break;
			case 'Q':
				beg = new String("What ");
				end = new String("?");
				needCapital = false;
				break;
			case 'E':
				end = new String("!");
				break;
			}
			for(int j = 1; j < sentences.get(i).length; ++j) {
				char ch2 = sentences.get(i)[j];
				switch(ch2) {
				case 'T':
					{
						char[] curr = new String("the").toCharArray();
						needCapital = cap(needCapital, curr);
						mid += new String(curr);
					}	
					break;
				case 'A':
					{
						char[] curr = new char[1];
						char[] next = new char[1];
						char ch3 = sentences.get(i)[j+1];
						switch(ch3) { // Don't worry about buffer over-run!
						case 'N': next = Ns.get(Ni); break;
						case 'C': next = Cs.get(Ci); break;
						case 'V': next = Vs.get(Vi); break;
						case 'J': next = Js.get(Ji); break;
						case 'B': next = Bs.get(Bi); break;
						case 'P': next = Ps.get(Pi); break;
						}
						switch(next[0]) {
						case 'a': curr = new String("an").toCharArray(); break;
						case 'e': curr = new String("an").toCharArray(); break;
						case 'i': curr = new String("an").toCharArray(); break;
						case 'o': curr = new String("an").toCharArray(); break;
						case 'u': curr = new String("an").toCharArray(); break;
						default: curr = new String("a").toCharArray(); break;
						}
						needCapital = cap(needCapital,curr);
						mid += new String(curr);
					}
					break;
				case 'N': { char[] curr = Ns.get(Ni++); Ni = Ni % Ns.size(); needCapital = cap(needCapital,curr); mid += new String(curr); } break;
				case 'C': { char[] curr = Cs.get(Ci++); Ci = Ci % Cs.size(); needCapital = cap(needCapital,curr); mid += new String(curr); } break;
				case 'V': { char[] curr = Vs.get(Vi++); Vi = Vi % Vs.size(); needCapital = cap(needCapital,curr); mid += new String(curr); } break;
				case 'J': { char[] curr = Js.get(Ji++); Ji = Ji % Js.size(); needCapital = cap(needCapital,curr); mid += new String(curr); } break;
				case 'B': { char[] curr = Bs.get(Bi++); Bi = Bi % Bs.size(); needCapital = cap(needCapital,curr); mid += new String(curr); } break;
				case 'P': { char[] curr = Ps.get(Pi++); Pi = Pi % Ps.size(); needCapital = cap(needCapital,curr); mid += new String(curr); } break;
				}
				if(j < sentences.get(i).length-1)
					mid += new String(" ");
			}
			System.out.print(beg);
			System.out.print(mid);
			System.out.print(end);
			if(i < sentences.size()-1)
				System.out.print(' ');
		}
		System.out.println();
	}
}
