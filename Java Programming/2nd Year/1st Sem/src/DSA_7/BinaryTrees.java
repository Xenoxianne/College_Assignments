/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Binary Trees arrion and Traversal
* IDE: VSCode
*/

import java.util.Scanner;
import java.util.ArrayList;

public class BinaryTrees {

    /**Creation of Nodes wherein data is stored*/
    public static class Node{    
        String data;    
        Node left;    
        Node right;    
        public Node(String data){    
            //Assign data to the new node, set left and right children to null    
            this.data = data;    
            this.left = null;    
            this.right = null;    
            }    
        }    
    
    //root of binary tree
    public static Node root;

    /** Preorder Traversal*/
    public static void preorder(Node root){
        if (root == null)
        return;
      
        if(root.data != null) System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    /** Inorder Traversal*/
    public static void inorder(Node root){
        if (root == null)
        return;
    
        inorder(root.left);
        if(root.data != null) System.out.print(root.data + " ");
        inorder(root.right);
    }

    /** Postorder Traversal*/
    public static void postorder(Node root){
        if (root == null)
        return;
    
        postorder(root.left);
        postorder(root.right);
        if(root.data != null) System.out.print(root.data + " ");
    }

    /** Printing of values*/
    public static void display(Node node){
        //No input found
        if (node == null || (node.left == null && node.right == null))
            return;

        //Only left is null
        if (node.left == null) 
            System.out.println(node.data + "\t\tnull\t\t" + node.right.data);

        //Right is null
        else if (node.right == null) 
            System.out.println(node.data + "\t\t" + node.left.data + "\t\tnull");

        //Everything has value
        else 
            System.out.println(node.data + "\t\t" + node.left.data + "\t\t" + node.right.data);
  
        display(node.left);     //check left node
        display(node.right);    //check right node
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayList<String> arr = new ArrayList<>();

        //user input
        System.out.println("Input:");
        for(int i = 0; i < 6; i++) {
            String input = in.nextLine().replaceAll("[()]",""); //delete elemts with ()
            String[] temp = input.split(",");   //separate data between ,
            for(var t : temp)
                arr.add(t); //add separated data in array
        }

        //store literal null for String "null"
        for(int i = 0; i < arr.size(); i++){
            if(arr.get(i).equalsIgnoreCase("null"))
                arr.set(i,null);
        }

        //Store in tree the respective values in array
        BinaryTrees.root = new Node(arr.get(0));
        BinaryTrees.root.left = new Node(arr.get(1));
        BinaryTrees.root.right = new Node(arr.get(2));
        BinaryTrees.root.left = new Node(arr.get(3));
        BinaryTrees.root.left.left= new Node(arr.get(4));
        BinaryTrees.root.left.right = new Node(arr.get(5));
        BinaryTrees.root.left.left = new Node(arr.get(6));
        BinaryTrees.root.left.left.left = new Node(arr.get(7));
        BinaryTrees.root.left.left.right = new Node(arr.get(8));
        BinaryTrees.root.right = new Node(arr.get(9));
        BinaryTrees.root.right.left = new Node(arr.get(10));
        BinaryTrees.root.right.right = new Node(arr.get(11));
        BinaryTrees.root.right.left = new Node(arr.get(12));
        BinaryTrees.root.right.left.left = new Node(arr.get(13));
        BinaryTrees.root.right.left.right = new Node(arr.get(14));
        BinaryTrees.root.right.right = new Node(arr.get(15));
        BinaryTrees.root.right.right.left = new Node(arr.get(16));
        BinaryTrees.root.right.right.right =new Node(arr.get(17));
    
        //output
        System.out.print("\nOutput\nNode:\t\tL-Subtree\tR-Subtree\n");
        display(root);
        
        System.out.print("\nRoot of the Tree: " + root.data);
        System.out.print("\n\nPreorder Traversal: ");   preorder(root);
        System.out.print("\nInorder Traversal: ");    inorder(root);
        System.out.print("\nPostorder Traversal: ");  postorder(root);
    }
}
