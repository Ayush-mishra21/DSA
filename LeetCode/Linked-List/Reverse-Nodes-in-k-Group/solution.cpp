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
    ListNode solve(ListNode currhead, ListNode node, ListNode prev int k, int count){
        if(node == null)return node;
        if(count == k){
            ListNode temp = node.next, temp1 = node;
            node.next = null;
            ListNode prev = null, curr;
            while(currhead != null){
                curr = currhead.next;
                currhead.next = prev;
                prev = currhead;
                temp1 = currhead;
                currhead = curr;
            }
            temp1.next = solve(temp, temp, k, 1);
            return prev;
        }
        else{
            node.next = solve(currhead, node.next, k, count + 1);
            return node;
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        return solve(head, head, prev, k, 1);
    }
}