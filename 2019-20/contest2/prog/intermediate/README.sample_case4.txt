What I believe should be the right induction and answer:

Step1:

ABCDEFGHIJKLMNO
ABKCLDZZHQJWWLX

Step2: Delete leading 'AB' from both rows

CDEFGHIJKLMNO
KCLDZZHQJWWLX

Step3: Delete 'C' from top row, 'KC' from bottom row. Delete 'D' from top row, 'LD' from bottom row. Delete 'H' from bottom row, 'GH' from top row. Delete 'L' from top row, 'WL' from bottom row.

EFIJKMNO
ZZQJWX

Step4: Delete 'J' from both rows

EFIKMNO
ZZQWX

ord('E') - ord('Z') = -21
ord('F') - ord('Z') = -20
ord('I') - ord('Q') = -8
ord('K') - ord('W') = -12
ord('M') - ord('X') = -11

-21 + (-20) + (-8) + (-12) + (-11) + 2 = -70


What I blieve how ACSL sample made the mistake:


Step1:

ABCDEFGHIJKLMNO
ABKCLDZZHQJWWLX

Step2: Delete leading 'AB' from both rows

CDEFGHIJKLMNO
KCLDZZHQJWWLX

Step3: Delete 'C' from top row, 'KC' from bottom row. Delete 'D' from top row, 'LD' from bottom row. Do NOT delete 'H' from bottom row nor 'GH' from top row. Do NOT delete 'J' from bottom row nor 'IJ' from top row

EFGHIJKLMNO
ZZHQJWWLX

Step4: Delete 'L' from both rows

EFGHIJKMNO
ZZHQJWWX

ord('E') - ord('Z') = -21
ord('F') - ord('Z') = -20
ord('G') - ord('H') = -1
ord('H') - ord('Q') = -9
ord('I') - ord('J') = -1
ord('J') - ord('W') = -13
ord('K') - ord('W') = -12
ord('M') - ord('X') = -11

-21 + (-20) + (-1) + (-9) + (-1) + (-13) + (-12) + (-11) + 2 = 86

When use the bottom approach on other test cases, it is impossible to have the results in the provided sample.
