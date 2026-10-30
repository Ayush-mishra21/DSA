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
    ListNode solve(ListNode head, int k, int count){
        if(head == null)return head;
        if(count == k){

        }
        else{
            return solve(node->next, k, )
        }
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        return solve(head, k, 1);
    }
}