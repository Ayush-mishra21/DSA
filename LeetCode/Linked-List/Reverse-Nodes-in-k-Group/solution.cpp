/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode solve(ListNode currhead, ListNode node, ListNode prev, int k, int count){
        if(node == null)return node;
        if(count == k){
            ListNode temp = node.next, temp1 = currhead;
            node.next = null;
            ListNode curr, newprev = prev;
            while(currhead != null){
                curr = currhead.next;
                currhead.next = prev;
                prev = currhead;
                currhead = curr;
            }
            temp1.next = solve(temp, temp, temp1, k, 1);
            return newprev;
        }
        else{
            return solve(currhead, node.next, prev, k, count + 1);
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        return solve(head, head, null, k, 1);
    }
}