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
    ListNode solve(ListNode currhead, ListNode node, int k, int count){
        if(node == null)return node;
        if(count == k - 1){
            ListNode temp = node.next, call = null;
            if(temp.next){
                call = temp.next;
            }
            node.next = null;
            ListNode prev = null, curr, temp1 = node;
            while(currhead != null){
                curr = currhead.next;
                currhead.next = prev;
                prev = currhead;
                currhead = curr;
            }
            temp1.next = solve(call, call, k, 1);
            return prev;
        }
        else{
            return node.next = solve(currhead, node.next, k, count + 1);
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        return solve(head, head, k, 1);
    }
}