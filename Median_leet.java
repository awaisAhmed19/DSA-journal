public class Median_leet{
       public double findMedianSortedArrays(int[] nums1, int[] nums2) {
                int[] output=new int[nums1.length+nums2.length];
        
        int size=output.length;
        int i=0;
        int j=0;
        int k=0;
        while(i<nums1.length&&j<nums2.length){
          if(nums1[i]<nums2[j]){
            output[k]=nums1[i];
            k++;
            i++;
          }else{
            output[k]=nums2[j];
            k++;
            j++;
      }
    }
        while(i<nums1.length){
          output[k++]=nums1[i++];
    }
        while(j<nums2.length){
          output[k++]=nums2[j++];
    }
        if(output.length%2==0){
            int mid=(output.length-1)/2;
            return (double)(output[mid]+output[mid+1])/2; 
        }
        return (double)(output[(output.length-1)/2]);

    }    
  public static void main(String args[]){
    Median_leet m=new Median_leet();
    int[] nums1={2,2,2,2,2,2,22};
    int[] nums2={2,3,4,5,7,8,9,6,5,4,3,2};
    double out=m.findMedianSortedArrays(nums1,nums2);
    //for(int i=0;i<out.length;i++){
      //System.out.println(out[i]);
    //}
    System.out.println(out);
  }
}
