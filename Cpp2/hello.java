public class Dijkstra extends Configured implements Tool {
 public static String OUT = "outfile";
 public static String IN = "inputlarger”;
 public static class TheMapper extends Mapper<LongWritable, Text, LongWritable, Text> {
 public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
Text word = new Text();
 String line = value.toString();//looks like 1 0 2:3:
 String[] sp = line.split(" ");//splits on space
 int distanceadd = Integer.parseInt(sp[1]) + 1;
 String[] PointsTo = sp[2].split(":");
 for(int i=0; i<PointsTo.length; i++){
 word.set("VALUE "+distanceadd);//tells me to look at distance value
 context.write(new LongWritable(Integer.parseInt(PointsTo[i])), word);
 word.clear(); }
 //pass in current node's distance (if it is the lowest distance)
 word.set("VALUE "+sp[1]);
 context.write( new LongWritable( Integer.parseInt( sp[0] ) ), word );
 word.clear();
 word.set("NODES "+sp[2]);//tells me to append on the final tally
 context.write( new LongWritable( Integer.parseInt( sp[0] ) ), word );
 word.clear();
