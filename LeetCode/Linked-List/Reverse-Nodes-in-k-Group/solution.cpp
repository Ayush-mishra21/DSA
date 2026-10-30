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
    ListNode solve(ListNode node, int k, int count){
        if(head == null)return node;
        if(count == k){

        }
        else{
            return node->next =  solve(node->next, k, count + 1);
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        return solve(head, k, 1);
    }
}